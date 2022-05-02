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
            jsonData = '{"username": "' + input("Enter username: ") + '","password": "' + input("Enter passowrd: ") + '"'
            if loginOrSignup:
                jsonData += ',"email": "' + input("Enter email: ") + '"'
            jsonData += "}"
            
            # first the length in bytes, then the json data encoded
            messageToServer += len(jsonData).to_bytes(INT_SIZE, 'little')
            messageToServer += jsonData.encode()

            sock.send(messageToServer);
            
            data = sock.recv(5)
            dataLen = int.from_bytes(data[1:], 'little')
            print(sock.recv(dataLen).decode())

    except socket.error as e:
        print('Error!')
        print(e)