#pragma once
#include"../Room/Room.h"
#include<map>
#include<vector>

class RoomManager
{
public:
    //create a room and return its index
    int createRoom(const LoggedUser& roomCreator, RoomData& roomData);
    bool deleteRoom(const int id);
    unsigned int getRoomState(const int id) const;
    std::vector<RoomData> getRooms() const;
    Room& getRoomById(const int id);
private:
    int m_nextIndex = 1;
    std::map<int, Room> m_rooms;
};