
from ClientClass import Client



print('setting up clients')
client1 = Client('Client 1')
client1.client_msg()

client2 = Client('Client 2')
client2.client_msg()

client3 = Client('Client 3')
client3.client_msg()

client4 = Client('Client 4')
client4.client_msg()


client1.client_recieve()
client2.client_recieve()
client3.client_recieve()
client4.client_recieve()

client1.find_average()
client2.find_average()
client3.find_average()
client4.find_average()

client1.find_offset()
client2.find_offset()
client3.find_offset()
client4.find_offset()

client1.adjust_time()
client2.adjust_time()
client3.adjust_time()
client4.adjust_time()
