import socket
port=12345
ss=socket.socket()#server socket
ss.bind(("127.0.0.1",port))
ss.listen()
conn,address=ss.accept()
print("Established connection with ",address)
data=conn.recv(1024).decode()
x=data.upper()
print("String converted to upper")
conn.send(x.encode())
conn.close()
