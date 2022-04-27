#include "LoginRequestHandler.h"
#include "JsonRequestPacketDeserializer.h"
#include <iostream>

bool LoginRequestHandler::isRequestRelevant(RequestInfo req) {
    int code = ((unsigned char)req.buffer[0]);
    return code == LOGIN_CODE || code == SIGNUP_CODE;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo req) {
    if ((unsigned char)req.buffer[0] == LOGIN_CODE) {
        LoginRequest logReq = JsonRequestPacketDeserializer::deserializeLoginRequest(req.buffer);
        std::cout << logReq.username << '\n' << logReq.password << std::endl;
        return RequestResult();
    }

    SignupRequest signupReq = JsonRequestPacketDeserializer::deserializeSignupRequest(req.buffer);
    std::cout << signupReq.username << '\n' << signupReq.password << '\n' << signupReq.email << std::endl;
    return RequestResult();
}
