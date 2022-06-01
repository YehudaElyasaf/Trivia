#include "RoomHandler.h"
#include "../Serializing/JsonResponsePacketSerializer.h"

RequestResult getRoomState(RoomManager& roomManager, const unsigned int roomId, IRequestHandler* handler) {
	Room room = roomManager.getRoomById(roomId);
	RoomData roomData = room.getRoomData();

	std::string buffer = JsonResponsePacketSerializer::serializeResponse(GetRoomStateResponse{
		true, roomData.isActive, room.getAllUsers(), roomData.numOfQuestionsInGame, roomData.timePerQuestion });
	return RequestResult{ buffer, handler };
}