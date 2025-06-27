import socket
host="127.0.0.1"
port=10001
cs=socket.socket()#client socket
cs.connect((host,port))
x="Hello"
while(x!="exit"):
    x=input("Enter client message: ")
    cs.send(x.encode())
    data=cs.recv(1024).decode()
    print(data)
cs.close()
