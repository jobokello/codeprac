
from xmlrpc.server import SimpleXMLRPCServer, SimpleXMLRPCRequestHandler


class RequestHandler(SimpleXMLRPCRequestHandler):
    rpc_paths = ('/RPC2',)

class Server(object):
    server = None
    time_list = []

    def __init__(self):
        self.server = SimpleXMLRPCServer(('localhost', 4444), requestHandler=RequestHandler)
        self.time_list = []

    def listen(self, time):
        self.time_list.append(time)
        return 'Recieved'

    def get_all_time(self):
        if(len(self.time_list) == 0):
            return 'No Time Has been submitted'
        else:
            return self.time_list

    def reg_funcs(self):
        if(self.server != None):
            self.server.register_function(self.listen)
            self.server.register_function(self.get_all_time)

    def start_server(self):
        self.server.serve_forever()
