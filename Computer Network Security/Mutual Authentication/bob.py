#Okello Job Opiyo
#P15/37353/2016
#CSC 411
#mutual Authentication Bob code

import socket
import os

HOST = ''
PORT = [12345,23456,34567,45678]
SHARED_KEY = 10923874576
challenge_bytes = os.urandom(4)
challenge = int.from_bytes(challenge_bytes,'big')

temp = []

# Bob receives communication request from Alice
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT[0]))
    s.listen(1)
    conn, addr = s.accept()
    with conn:
        print('Connected by', addr)
        while True:
            data = conn.recv(1024)
            if not data: break
            print("Alice: ",data.decode('utf-8'))
            conn.sendall(b'')
    conn.close()

# Bob sends a challenge RB to Alice, shown as challenge_bytes.
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as a:
    a.connect((HOST, PORT[1]))
    a.sendall(challenge_bytes)

# When Bob receives the response alice_response to his challenge challenge_bytes, he can decrypt the message using the SHARED_KEY again to see if it contains challenge_bytes.
# If so, he then knows that Alice is on the other side. Bob also receives Alice challenge (alice_challenge_bytes)
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as b:
    b.bind((HOST, PORT[2]))
    b.listen(1)
    conn, addr = b.accept()
    with conn:
        print('Connected by', addr)
        while True:
            data = conn.recv(1024)
            alice_challenge_bytes = conn.recv(1024)
            alice_response = int.from_bytes(data,'big')
            if not data: break
            if not alice_challenge_bytes: break
            temp.append(alice_challenge_bytes)
            temp.append(alice_response)
            print("Bob's encrypted challenge from Alice : ",alice_response)
            conn.sendall(b'')
    conn.close()

# Decryption using the XOR operator
decrypted_alice_response = temp[1]^SHARED_KEY
encrypted_alice_challenge = int.from_bytes(temp[0],'big')^SHARED_KEY

if decrypted_alice_response == challenge:
    print("I have verified Alice")
    # Bob sends to Alice her encrypted challenge
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as c:
        c.connect((HOST, PORT[3]))
        c.sendall(encrypted_alice_challenge.to_bytes(1024,'big'))
else:
    print("I have not verified Alice")
