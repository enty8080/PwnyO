import socket

def send(c, tag, data):
    c.send(tag.to_bytes(2, 'little'))
    c.send(len(data).to_bytes(4, 'little'))
    c.send(data.encode())

def read(c):
    tag = c.recv(2)
    size = c.recv(4)

    tag = int.from_bytes(tag, 'little')
    size = int.from_bytes(size, 'little')

    if size > 0:
        return tag, c.recv(size)

    return tag, b''

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM, 0)
s.bind(('127.0.0.1', 8888))
s.listen()
c, a = s.accept()

print(f"* Connection from {a[0]}")

send(c, 0, 'hi')
