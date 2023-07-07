import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
s.bind(('127.0.0.1', 8888))
s.listen()
c, a = s.accept()

print(f"* Connection from {a[0]}")

data = input('> ')

tag = 0
size = len(data)

c.send(tag.to_bytes(2, 'little'))
c.send(size.to_bytes(4, 'little'))
c.send(data.encode())
