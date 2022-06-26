#include "GameRequestHandler.h"
#include "../Defines/responses.h"
#include "../Serializing/JsonResponsePacketSerializer.h"
#include "../Serializing/JsonRequestPacketDeserializer.h"
#include "../Game/Game.h"

GameRequestHandler::GameRequestHandler(const unsigned int roomId, const LoggedUser& user, RoomManager& roomManager, RequestHandlerFactory& fact, Game& game):
	m_roomId(roomId), m_user(user), m_roomManager(roomManager), m_handlerFactory(fact), m_game(game) {}

bool GameRequestHandler::isRequestRelevant(RequestInfo req) {
	return req.buffer[0] >= GET_RESULTS_CODE && req.buffer[0] <= LEAVE_GAME_CODE;
}

RequestResult GameRequestHandler::handleRequest(RequestInfo req) {
	if (req.buffer[0] == GET_RESULTS_CODE)
		return getResults();
	if (req.buffer[0] == SUBMIT_ANS_CODE)
		return submitAns(req);
	if (req.buffer[0] == GET_QUESTION_RESP_CODE)
		return questionResponse();
	if (req.buffer[0] == LEAVE_GAME_CODE)
		return leaveGame();
}

std::string GameRequestHandler::getUsername() const {
	return m_user.m_username;
}

Game& GameRequestHandler::getGame() {
	return m_game;
}

unsigned int GameRequestHandler::getRoomId() const {
	return m_roomId;
}

RequestResult GameRequestHandler::getResults() {
	GetGameResultsResponse resp;
	resp.status = !(m_roomManager.getRoomById(m_roomId).getRoomData().isActive);

	for (auto user : m_game.getPlayers()) {
		resp.results.emplace_back(user.first.m_username, user.second.correctAnswerCount,
			user.second.wrongAnswerCount, user.second.averageAnswerTime);
	}
	return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}

RequestResult GameRequestHandler::leaveGame() {
	m_game.removePlayer(m_user);
	return { JsonResponsePacketSerializer::serializeResponse({LeaveGameResponse{m_game.removePlayer(m_user)}}), m_handlerFactory.createMenuRequestHandler(getUsername())};
}

RequestResult GameRequestHandler::submitAns(RequestInfo req) {
	SubmitAnswerRequest request = JsonRequestPacketDeserializer::deserializeSubmitAnswerRequest(req.buffer);
	std::string correctAns("");
	unsigned int status = true;

	// if the client was out of time, the status tells it has failed.
	try {
		correctAns = m_game.submitAnswer(m_user, request.answer);
		m_roomManager.getRoomById(m_roomId).getRoomData().isActive = m_game.isGameFinished();
	}
	catch (const QuestionTimeOutException& ex) {
		status = false;
	}
	return { JsonResponsePacketSerializer::serializeResponse({SubmitAnswerResponse{status, correctAns}}), this };
}

RequestResult GameRequestHandler::questionResponse() {
	Question q = m_game.getQuestionForUser(m_user);
	GetQuestionResponse resp{ true, q.getQuestion(), q.getPossibleAnswers() };

	return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}