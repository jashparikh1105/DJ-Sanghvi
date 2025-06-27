import socket
host="127.0.0.1"
port=10001
ss=socket.socket()#server socket
ss.bind((host,port))
ss.listen()
conn,address=ss.accept()
print("Established connection with ",address)
x="Hello"
while(x!="exit"):
    data=conn.recv(1024).decode()
    print(data)
    sum=int(data[0:2])+int(data[3:6])
    print(sum)
    x=input("Enter server message: ")
    conn.send(x.encode())
conn.close()