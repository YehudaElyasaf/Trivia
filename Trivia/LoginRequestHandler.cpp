#include "LoginRequestHandler.h"
#include "JsonRequestPacketDeserializer.h"
#include <iostream>

bool LoginRequestHandler::isRequestRelevant(RequestInfo req) {
    int code = ((unsigned char)req.buffer[0]);
    return code == LOGIN_CODE || code == SIGNUP_CODE;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo req) {
    if ((unsigned char)req.buffer[0] == LOGIN_CODE) {
        return login(req);
    }

    return signup(req);
}

RequestResult LoginRequestHandler::login(RequestInfo req) {
    LoginRequest logReq = JsonRequestPacketDeserializer::deserializeLoginRequest(req.buffer);

    return RequestResult(m_loginManager.login(logReq.username, logReq.password));
}

RequestResult LoginRequestHandler::signup(RequestInfo req) {
    SignupRequest signupReq = JsonRequestPacketDeserializer::deserializeSignupRequest(req.buffer);
    
    return RequestResult(m_loginManager.signup(signupReq.username, signupReq.password, signupReq.email));
}
