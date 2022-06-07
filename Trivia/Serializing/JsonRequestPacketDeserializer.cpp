#include "../Serializing/JsonRequestPacketDeserializer.h"

#define DATA_START 1

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(const std::string& buffer) {
    LoginRequest out{"", ""};
    //ignore code field
    json data = json::parse(buffer.substr(DATA_START));

    out.username = data["username"];
    out.password = data["password"];

    return out;
}

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(const std::string& buffer) {
    SignupRequest out{"", "", ""};
    //ignore code field
    json data = json::parse(buffer.substr(DATA_START));

    out.username = data["username"];
    out.password = data["password"];
    out.email = data["email"];

    return out;
}

GetPlayersInRoomRequest JsonRequestPacketDeserializer::deserializeGetPlayersInRoomRequest(const std::string& buffer) {
    GetPlayersInRoomRequest out{0};
    json data = json::parse(buffer.substr(DATA_START));
    out.roomId = stoi(std::string(data["roomId"]));
    return out;
}

JoinRoomRequest JsonRequestPacketDeserializer::deserializeJoinRoomRequest(const std::string& buffer) {
    JoinRoomRequest out{0};
    json data = json::parse(buffer.substr(DATA_START));
    out.roomId = stoi(std::string(data["roomId"]));
    return out;
}

CreateRoomRequest JsonRequestPacketDeserializer::deserializeCreateRoomRequest(const std::string& buffer) {
    CreateRoomRequest out{"", 0, 0, 0};
    json data = json::parse(buffer.substr(DATA_START));
    out.answerTimeout = stoi(std::string(data["answerTimeout"]));
    out.maxUsers = stoi(std::string(data["maxUsers"]));
    out.questionCount = stoi(std::string(data["questionCount"]));
    out.roomName = data["roomName"];
    return out;
}

SubmitAnswerRequest JsonRequestPacketDeserializer::deserializeSubmitAnswerRequest(const std::string& buffer) {
    SubmitAnswerRequest out;
    json data = json::parse(buffer.substr(DATA_START));

    out.answerId = stoi(std::string(data["answerId"]));
    return out;
}
