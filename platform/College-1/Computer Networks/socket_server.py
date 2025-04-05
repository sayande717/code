import socket

def start_server():
    # Create a socket object
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    # Define the host and port
    host = '127.0.0.1'  # Localhost
    port = 12345        # Port to listen on

    # Bind the socket to the address and port
    server_socket.bind((host, port))

    # Start listening for incoming connections
    server_socket.listen(5)  # Maximum number of queued connections

    print(f"Server started and listening on {host}:{port}")

    while True:
        # Accept a connection
        client_socket, client_address = server_socket.accept()
        print(f"Connection established with {client_address}")

        # Send a welcome message to the client
        client_socket.send(b"Welcome to the server!")

        # Close the client connection
        client_socket.close()

if __name__ == "__main__":
    start_server()