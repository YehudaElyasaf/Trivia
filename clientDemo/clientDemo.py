import socket

PORT = 4242
IP = '127.0.0.1'

BUFFER_SIZE = 1024

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
    try:
        sock.connect((IP, PORT))
        print(sock.recv(BUFFER_SIZE).decode())

        while True:
            command = input('Enter message to server: ')
            sock.send(command.encode());

    except socket.error as e:
        print('Error!')
        print(e)