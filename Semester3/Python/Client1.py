import socket
host="127.0.0.1"
port=12345
cs=socket.socket()#client socket
cs.connect((host,port))
x=input("Enter input string: ")
cs.send(x.encode())
data=cs.recv(1024).decode()
print(data)
cs.close()
