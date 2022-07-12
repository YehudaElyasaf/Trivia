#include "../Handlers/LoginRequestHandler.h"
#include "../Serializing/JsonRequestPacketDeserializer.h"
#include "../Serializing/JsonResponsePacketSerializer.h"
#include <iostream>

LoginRequestHandler::LoginRequestHandler(LoginManager& manager, RequestHandlerFactory& factory) :
	m_handlerFactory(factory), m_loginManager(manager) { }

bool LoginRequestHandler::isRequestRelevant(RequestInfo req) {
	int code = ((unsigned char)req.buffer[0]);
	return code == LOGIN_CODE || code == SIGNUP_CODE;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo req) {
	if ((unsigned char)req.buffer[0] == LOGIN_CODE) {
		return login(req);
	}

	return signup(req);
}

HANDLER_TYPE LoginRequestHandler::getType() const {
	return LOGIN;
}

std::string LoginRequestHandler::getUsername() const
{
	throw NoUsernameException();
	//before login, there is no username
}

RequestResult LoginRequestHandler::login(RequestInfo req) {
	LoginRequest logReq = JsonRequestPacketDeserializer::deserializeLoginRequest(req.buffer);
	LoginResponse resp = { m_loginManager.login(logReq.username, logReq.password) };
	
	// if login worked, have a menu handler. if not, you should still have this handler
	if (resp.status)
		return { JsonResponsePacketSerializer::serializeResponse(resp), m_handlerFactory.createMenuRequestHandler(logReq.username)};
	return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}

RequestResult LoginRequestHandler::signup(RequestInfo req) {
	SignupRequest signupReq = JsonRequestPacketDeserializer::deserializeSignupRequest(req.buffer);
	SignupResponse resp = { m_loginManager.signup(signupReq.username, signupReq.password, signupReq.email) };
	
	return { JsonResponsePacketSerializer::serializeResponse(resp), this };
}
