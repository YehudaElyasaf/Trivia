#include "RoomHandler.h"
#include "../Serializing/JsonResponsePacketSerializer.h"

RequestResult getRoomState(RoomManager& roomManager, const unsigned int roomId, IRequestHandler* handler, RequestHandlerFactory& factory) {
	try {
		Room room = roomManager.getRoomById(roomId);
		RoomData roomData = room.getRoomData();

		std::string buffer = JsonResponsePacketSerializer::serializeResponse(GetRoomStateResponse{
			roomData.isActive, roomData.isActive, room.getAllUsers(), roomData.numOfQuestionsInGame, roomData.timePerQuestion });
		return RequestResult{ buffer, handler };
	}
	catch (const std::exception& ex) {
		std::string username = handler->getUsername();
		return { JsonResponsePacketSerializer::serializeResponse(ErrorResponse{ex.what()}), factory.createMenuRequestHandler(username)};
	}
}