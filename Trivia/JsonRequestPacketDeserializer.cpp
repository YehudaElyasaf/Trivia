#include "JsonRequestPacketDeserializer.h"

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(const std::string& buffer) {
    LoginRequest out = { "", "" };
    //ignore code field
    json data = buffer.substr(1);

    out.username = data["username"];
    out.password = data["password"];

    return out;
}

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(const std::string& buffer) {
    SignupRequest out = { "", "", "" };
    //ignore code field
    json data = buffer.substr(1);

    out.username = data["username"];
    out.password = data["password"];
    out.email = data["email"];

    return out;
}
