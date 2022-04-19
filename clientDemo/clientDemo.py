import socket

SERVER_PORT = 4242
SERVER_IP = '127.0.0.1'

BUFFER_SIZE = 1024

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
    try:
        sock.connect((SERVER_IP, SERVER_PORT))
        print(sock.recv(BUFFER_SIZE).decode())

        while True:
            messageToServer = input('Enter message to server: ')
            sock.send(messageToServer.encode());

    except socket.error as e:
        print('Error!')
        print(e)