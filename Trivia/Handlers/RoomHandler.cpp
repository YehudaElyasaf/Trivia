#include "RoomHandler.h"
#include "../Serializing/JsonResponsePacketSerializer.h"

RoomHandler::RoomHandler(unsigned int roomId, LoggedUser user, RoomManager& roomManager, RequestHandlerFactory& fact) :
	m_roomId(roomId), m_user(user), m_roomManager(roomManager), m_handlerFactory(fact) {}

RequestResult RoomHandler::getRoomState() {
	Room room = m_roomManager.getRoomById(m_roomId);
	RoomData roomData = room.getRoomData();

	std::string buffer = JsonResponsePacketSerializer::serializeResponse(GetRoomStateResponse{
		true, roomData.isActive, room.getAllUsers(), roomData.numOfQuestionsInGame, roomData.timePerQuestion });
	return { buffer, this };
}
