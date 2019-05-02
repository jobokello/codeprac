
#Okello Job Opiyo
#P15/37353/2016
#CSC 411
#mutual Authentication Alice code


import socket
import os

HOST = 'localhost'
PORT = [12345,23456,34567,45678]
SHARED_KEY = 10923874576
encrypted_bobs_challenge = 0
challenge_bytes = os.urandom(4)
challenge = int.from_bytes(challenge_bytes,'big')
temp = []

# Alice sends her identity to Bob (message 1), indicating that she wants to set up a communication channel between the two.
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT[0]))
    s.sendall(b'Its Alice and I want to communicate with you, Bob')

# Alice must encrypt the challenge with the secret key SHARED_KEY that she shares with Bob,
# and return the encrypted challenge to Bob. This response is shown as encrypted_bobs_challenge.
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as a:
    a.bind((HOST, PORT[1]))
    a.listen(1)
    conn, addr = a.accept()
    with conn:
        print('Connected by', addr)
        while True:
            data = conn.recv(1024)
            bobs_challenge_bytes = data
            bobs_challenge = int.from_bytes(bobs_challenge_bytes, 'big')
            if not data: break
            print("Bob challenge: ",bobs_challenge)
            conn.sendall(b'')
            encrypted_bobs_challenge = bobs_challenge ^ SHARED_KEY
    conn.close()

# Alice has not yet verified that it is Bob is on the other side of the channel.
# She sends a challenge challenge_bytes
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as b:
    b.connect((HOST, PORT[2]))
    b.sendall(encrypted_bobs_challenge.to_bytes(1024,'big'))
    b.sendall(challenge_bytes)

# Alice received an encrypted challenge from Bob and verifies it
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as c:
    c.bind((HOST, PORT[3]))
    c.listen(1)
    conn, addr = c.accept()
    with conn:
        print('Connected by', addr)
        while True:
            data = conn.recv(1024)
            bob_response = int.from_bytes(data,'big')
            if not data: break
            temp.append(bob_response)
            print("Alice's encrypted challenge from Bob : ",bob_response)
            conn.sendall(b'')
    conn.close()

# Decryption using the XOR operator
decrypted_bob_response = temp[0]^SHARED_KEY

if decrypted_bob_response == challenge:
    print("I have verified Bob")
    print("We can now communicate")
else:
    print("I have not verified Bob")