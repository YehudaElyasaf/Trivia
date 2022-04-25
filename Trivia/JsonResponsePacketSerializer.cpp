#include "JsonResponsePacketSerializer.h"

#include "json.h"

using json = nlohmann::json;

std::string JsonResponsePacketSerializer::serializeResponse(ErrorResponse resp) {
    std::string out = { (unsigned char)ERROR, 0 };
    json data;
    data["message"] = resp.message;

    // add the length of the json in bytes
    int dataLen = data.dump().length();
    unsigned char *len = (unsigned char*) &dataLen;

    for (int i = 0; i < sizeof(int); i++) {
        out += len[i];
    }

    out += data.dump();
    return out;
}

std::string JsonResponsePacketSerializer::serializeResponse(LoginResponse resp)
{
    return std::string();
}

std::string JsonResponsePacketSerializer::serializeResponse(SignupResponse resp) {
    return std::string();
}
