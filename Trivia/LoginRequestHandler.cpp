#include "LoginRequestHandler.h"
#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include <iostream>

LoginRequestHandler::LoginRequestHandler(LoginManager& manager, RequestHandlerFactory& factory) :
	m_handlerFactory(factory), m_loginManager(manager) { }

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
	LoginResponse resp = { m_loginManager.login(logReq.username, logReq.password) };
	return { JsonResponsePacketSerializer::serializeResponse(resp), m_handlerFactory.createMenuRequestHandler(logReq.username)};
}

RequestResult LoginRequestHandler::signup(RequestInfo req) {
	SignupRequest signupReq = JsonRequestPacketDeserializer::deserializeSignupRequest(req.buffer);
	SignupResponse resp = { m_loginManager.signup(signupReq.username, signupReq.password, signupReq.email) };
	return { JsonResponsePacketSerializer::serializeResponse(resp), m_handlerFactory.createMenuRequestHandler(signupReq.username) };
}
