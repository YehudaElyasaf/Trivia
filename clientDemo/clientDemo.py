import socket
import json

SERVER_PORT = 4242
SERVER_IP = '127.0.0.1'

BUFFER_SIZE = 1024
INT_SIZE = 4


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
    try:
        sock.connect((SERVER_IP, SERVER_PORT))
        print(sock.recv(BUFFER_SIZE).decode())

        while True:
            loginOrSignup = bool(int(input('Login or signup? (0 - login, 1 - signup): ')))
            # message code (login/signup)
            messageToServer = chr(loginOrSignup + 2).encode()

            # assemble json based of if it's login or signup
            jsonData = {"username": input("Enter username: "), "password": input("Enter passowrd: ")}
            if loginOrSignup:
                jsonData["email"] = input("Enter email: ")
            
            # first the length in bytes, then the json data encoded
            messageToServer += len(json.dumps(jsonData)).to_bytes(INT_SIZE, 'little')
            messageToServer += json.dumps(jsonData).encode()

            sock.send(messageToServer);
            
            data = sock.recv(5)
            dataLen = int.from_bytes(data[1:], 'little')
            response = json.loads(sock.recv(dataLen).decode())
            if "message" in response.keys():
                print("ERROR!", response["message"])
            else:
                print("login / signup worked?", bool(response["status"]))

    except socket.error as e:
        print('Error!')
        print(e)