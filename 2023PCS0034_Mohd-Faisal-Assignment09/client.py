import socket

def start_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(('127.0.0.1', 8888))

    while True:
        message = input("Enter message to send: ")
        client.send(message.encode('utf-8'))
        response = client.recv(1024)
        print(f"Server response: {response.decode('utf-8')}")

    client.close()

start_client()
