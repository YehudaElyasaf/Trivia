#pragma once
#include "IRequestHandler.h"
#include "../Room/RoomManager.h"
#include "RequestHandlerFactory.h"

RequestResult getRoomState(RoomManager& roomManager, const unsigned int roomId, IRequestHandler* handler);