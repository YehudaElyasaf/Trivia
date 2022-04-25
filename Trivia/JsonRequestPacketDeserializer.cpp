#include "JsonRequestPacketDeserializer.h"

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(const std::string& buffer) {
    LoginRequest out = { "", "" };
    // read data from the sixth char so it will read the json, not the part of the length 
    json data = buffer.substr(sizeof(int) + 1);

    out.username = data["username"];
    out.password = data["password"];

    return out;
}

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(const std::string& buffer) {
    SignupRequest out = { "", "", "" };
    // read data from the sixth char so it will read the json, not the part of the length 
    json data = buffer.substr(sizeof(int) + 1);

    out.username = data["username"];
    out.password = data["password"];
    out.email = data["email"];

    return out;
}
