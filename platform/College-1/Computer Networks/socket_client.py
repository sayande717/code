import socket

def create_client_socket():
    # Define the server address and port
    server_address = '127.0.0.1'  # Replace with server IP if needed
    server_port = 12345          # Replace with the server's port

    # Create a socket object
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        # Connect to the server
        client_socket.connect((server_address, server_port))
        print(f"Connected to server at {server_address}:{server_port}")
    except ConnectionError as e:
        print(f"Failed to connect to server: {e}")
        client_socket.close()
        return None

    return client_socket

if __name__ == "__main__":
    client_socket = create_client_socket()
    if client_socket:
        # Example: Send a message to the server
        client_socket.sendall(b"Hello, Server!")
        # Close the socket
        client_socket.close()