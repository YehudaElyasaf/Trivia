#pragma once
#include"Room.h"
#include<map>
#include<vector>

class RoomManager
{
public:
    void createRoom(const LoggedUser& roomCreator, const RoomData& roomData);
    void deleteRoom(const int id);
    unsigned int getRoomState(int id) const;
    std::vector<RoomData> getRooms() const;
private:
    std::map<int, Room> m_rooms;
};