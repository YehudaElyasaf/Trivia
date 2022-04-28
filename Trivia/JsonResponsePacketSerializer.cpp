#include "JsonResponsePacketSerializer.h"
#include "msgCodes.h"

std::string JsonResponsePacketSerializer::bitwiseLen(const json& data) {
    std::string out;
    int dataLen = data.dump().length();
    unsigned char* len = (unsigned char*)&dataLen;

    for (int i = 0; i < sizeof(int); i++) {
        out += len[i];
    }
    return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const ErrorResponse& resp) {
    std::string out = { (unsigned char)ERROR_CODE };
    json data;
    data["message"] = resp.message;

    out += bitwiseLen(data);
    
    out += data.dump();
    return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const LoginResponse& resp) {
    std::string out = { (unsigned char)LOGIN_CODE };
    json data;
    data["status"] = resp.status;

    out += bitwiseLen(data);
    out += data.dump();
    return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(const SignupResponse& resp) {
    std::string out = { (unsigned char)SIGNUP_CODE };
    json data;
    data["status"] = resp.status;

    out += bitwiseLen(data);
    out += data.dump();
    return out;
}