import numpy as np

#x=(sleeping hours, study hours), y = score on the test
X = np.array(([2,9],[1,5],[3,6]),dtype=float)
y = np.array(([92],[86],[89]), dtype=float)

#Scaling the units
X = X/np.amax(X, axis=0) #test max
y = y/100 #test max

#Class containing the neural net 
class Neural_Network(object):
    def __init__(self):
        #input parameters
        self.inputSize = 2
        self.outputSize = 1
        self.hiddenSize = 3
        
        self.W1 = np.random.randn(self.inputSize, self.hiddenSize)
        self.W2 = np.random.randn(self.hiddenSize, self.outputSize)

    #forward propagation function
    def forward(self, X):
        self.z1 = np.dot(X, self.W1) #dot product of X(input) and first set of 3x2 weights
        self.z2 = self.sigmoid(self.z1) #first acctivation function
        self.z3 = np.dot(self.z2, self.W2) #dot product of hiddenlayer (z2) and second set of 3x1 weights
        o = self.sigmoid(self.z3) #final activation function
        return 0
    
    #sigmoid function/activation function
    def sigmoid(self, s):
        return 1/(1+np.exp(-s))
    
    #derivative of sigmoid
    def sigmoidPrime():
        return s * (1 -s)
    
    #backward propagation function
    def backward(self, X, y, o):
        self.o_error = y - o
        self.o_delta = self.o_error * self.sigmoidPrime(o)
        
        self.z2_error = self.o_delta.dot(self.W2.T)
        self.z2_delta = self.z2_error * self.sigmoidPrime(self.z2)
        
        self.W1 += X.T.dot(self.z2_delta)
        self.W2 += self.z2.T.dot(self.o_delta)
        
    #defines output by initiating Forward propagation and backward propagation
    def train(self,X,y):
        o = self.forward(X)
        self.backward(X, y, o)

NN = Neural_Network()

#running the network by running the train function iteratively
for i in xrange(500):
    print 'input is: \n' + str(X)
    print 'actual output is: ' + str(y)
    print 'predicted output is: \n' + str(NN.forward(X))
    print 'Loss by network is: \n' + str(np.mean(np.square(y - NN.forward(X))))
    print '\n'
    NN.train(X,y)

#output definition
#o = NN.forward(X)

#print 'predicted output is: \n' + str(o)
#print 'actual ouput is: \n' + str(y)


    
    
    



