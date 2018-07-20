'''
Reg no. P15/37353/2016
Job Opiyo Okello
Genetic Algorithm

String Matching Genetic algorithm
'''
from fuzzywuzzy import fuzz
import string
import random

#define characteristics of each agent
class Agent(object):

	def __init__(self, length):

		self.string = ''.join(random.choice(string.letters) for _ in range(length))
		self.fitness = -1

	def __str__(self):

		return 'Generated String  ' + str(self.string) + ' Fitness to target string  = ' + str(self.fitness) + '%'

in_str = None
in_str_len = None
population = 26
generations = 1000

#initilaise the agents
def ga():
	agents = init_agents(population, in_str_len)

	for generation in xrange(generations):
		print 'Generation' + str(generation)

		agents = fitness(agents)
		agents = selection(agents)
		agents = crossover(agents)
		agents = mutation(agents)

		if any(agent.fitness >= 70 for agent in agents):
			print 'Threshold Met'
			exit(0)

def init_agents(population,length):
	return [Agent(length) for _ in xrange(population)]

#get the fitness of each generated string to the target string
def fitness(agents):
	for agent in agents:
		agent.fitness = fuzz.ratio(agent.string, in_str)

	return agents

#pic the best string instance from the generated strings
def selection(agents):
	agents = sorted(agents, key=lambda agent: agent.fitness, reverse = True) 
	print '\n' .join(map(str, agents))
	agents = agents[:int(0.2 + len(agents))]

	return agents

#crossover the best current fitness to come up with the new best children
def crossover(agents):

	offspring = []

	for _ in xrange((population - len(agents)) / 2):

		parent1 = random.choice(agents)
		parent2 = random.choice(agents)

		child1 = Agent(in_str_len)
		child2 = Agent(in_str_len)

		split = random.randomint(0, in_str_len)

		child1.string = parent1.string[0,split] + parent2.string[split:in_str_len]
		child2.string = parent2.string[0:split] + parent1.string[split:in_str_len]

		offspring.append(child1)
		offspring.append(child2)

	agents.extend(offspring)

	return agents

def mutation(agents):

	for agent in agents:

		for idx, param in enumerate(agent.string):

			if random.uniform(0.0, 1.0) <= 0.1: 
				agent.string = agent.string[0:idx] + random.choice(string.letters) + agent.string[idx+1:in_str_len]

	return agents

#get input string to be worked on
if __name__ == '__main__':
	in_str = 'job'
	in_str_len = len(in_str)
	ga()




		