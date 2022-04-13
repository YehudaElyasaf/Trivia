import socket

PORT = 4242
IP = '127.0.0.1'


with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
    try:
        sock.connect((IP, PORT))
        sock.send('Hello'.encode());

    except socket.error as e:
        print('Error!')
        print(e)