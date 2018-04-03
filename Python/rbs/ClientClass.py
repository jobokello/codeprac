-
-'''
-Innocent Kithinji
-job okello borrowed
-P15/36469/2016
assigmnent ya DS sem 5 for the first week
-'''
-
from xmlrpc.client import ServerProxy
from datetime import datetime


class Client():

    cl = None
    time = None
    others_time = None
    Hr_avg = None
    Min_avg = None
    Sec_avg = None
    Hr_offset = None
    Min_offset = None
    Sec_offset = None
    name = None

    def __init__(self, name):
        self.cl = ServerProxy('http://localhost:4444')
        self.time = str(datetime.now().time())
        self.others_time = []
        self.name = name
        if self.cl:
            print('{} is connected'.format(name))

    def client_msg(self):
        self.cl.listen(self.time)
        print('The time: {} has been broadcast'.format(self.time))

    def client_recieve(self):
        self.others_time = self.cl.get_all_time()
        print(self.others_time)

    def find_average(self):
        Hr_total = 0
        Min_total = 0
        Sec_total = 0
        for t in self.others_time:
            Hr_total += float(t.split(':')[0])
            Min_total += float(t.split(':')[1])
            Sec_total += float(t.split(':')[-1])

        # print('{} {} {}'.format(Hr_total,Min_total, Sec_total))

        self.Hr_avg = Hr_total/len(self.others_time)
        self.Min_avg = Min_total/len(self.others_time)
        self.Sec_avg = Sec_total/len(self.others_time)
        print('{} average : {} - {} - {}'.format(self.name, self.Hr_avg, self.Min_avg, self.Sec_avg))

    def find_offset(self):
        self.Hr_offset = float(self.time.split(':')[0])-self.Hr_avg
        self.Min_offset = float(self.time.split(':')[1]) - self.Min_avg
        self.Sec_offset = float(self.time.split(':')[-1]) - self.Sec_avg

        print('{} OffSets: {}, {}, {}'.format(self.name, self.Hr_offset,
              self.Min_offset,self.Sec_offset))

    def adjust_time(self):
        time = self.time
        new_Hour = float(time.split(':')[0])+self.Hr_offset
        new_Min = float(time.split(':')[1]) + self.Min_offset
        new_Sec = float(time.split(':')[-1])+self.Sec_offset

        new_Hour = int(new_Hour)
        new_Min = int(new_Min)
        new_Sec = int(new_Sec)

        if new_Hour < 0:
            new_Hour = 24 + new_Hour
        if new_Hour > 24:
            new_Hour = new_Hour - 24
        if new_Min < 0:
            new_Min = 60 + new_Min
        if new_Min > 60:
            new_Min = new_Min - 60
            new_Hour = new_Hour + 1
        if new_Sec < 0:
            new_Sec = 60 + new_Sec
        if new_Sec > 60:
            new_Sec = new_Sec - 60
            new_Min = new_Min + 1

        self.time = '{}:{}:{}'.format(new_Hour,new_Min, new_Sec)

        print('{}\'s new time is {}'.format(self.name, self.time))
