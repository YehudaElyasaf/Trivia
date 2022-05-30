#include "RoomHandler.h"

RequestResult RoomHandler::getRoomState() {
	Room room = m_roomManager.getRoomById(m_roomId);
	RoomData roomData = room.getRoomData();

	std::string buffer = JsonResponsePacketSerializer::serializeResponse(GetRoomStateResponse{
		roomData.isActive, room.getAllUsers(), roomData.numOfQuestionsInGame, room.timePerQuestion });
	return { buffer, this };
}
