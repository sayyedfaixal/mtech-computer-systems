import socket
import threading

MAX_CONNECTIONS = 5
current_connections = 0

def handle_client(client_socket):
    global current_connections
    if current_connections < MAX_CONNECTIONS:
        current_connections += 1
        print(f"Connected: {current_connections} clients connected.")

        while True:
            data = client_socket.recv(1024)
            if not data:
                break
            print(f"Received from client: {data.decode('utf-8')}")
            client_socket.send("Message received".encode('utf-8'))
        current_connections -= 1
        print(f"Disconnected: {current_connections} clients remaining.")
    else:
        client_socket.send("Server busy. Try again later.".encode('utf-8'))
    client_socket.close()

def start_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('127.0.0.1', 8888))
    server.listen(5)

    print("Server is listening...")

    while True:
        client, addr = server.accept()
        client_handler = threading.Thread(target=handle_client, args=(client,))
        client_handler.start()

start_server()
