#include"RoomManager.h"

int RoomManager::createRoom(const LoggedUser& roomCreator, const RoomData& roomData)
{
	int roomIndex = m_nextIndex;
	m_nextIndex++;
	m_rooms[roomIndex] = Room(roomCreator, roomData);
	
	return roomIndex;
}

bool RoomManager::deleteRoom(const int id)
{
	if (m_rooms.find(id) == m_rooms.end())
		//doesn't exist
		return false;

	//exists
	m_rooms.erase(id);
	return true;
}

unsigned int RoomManager::getRoomState(const int id) const
{
	return m_rooms.at(id).getRoomData().isActive;
}

std::vector<RoomData> RoomManager::getRooms() const
{
	std::vector<RoomData> roomDatas;
	for (auto room : m_rooms)
		roomDatas.push_back(room.second.getRoomData());

	return roomDatas;
}
