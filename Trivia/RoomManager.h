#pragma once
#include"Room.h"
#include<map>
#include<vector>

class RoomManager
{
public:
    //create a room and return its index
    int createRoom(const LoggedUser& roomCreator, const RoomData& roomData);
    bool deleteRoom(const int id);
    unsigned int getRoomState(const int id) const;
    std::vector<RoomData> getRooms() const;
private:
    int m_nextIndex = 0;
    std::map<int, Room> m_rooms;
};