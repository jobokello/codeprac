
'''
Okello Job Opiyo
Reg no. P15/37353/2016
KNN Algorithm
'''
import numpy as np
from math import sqrt
import matplotlib.pyplot as plt
import warnings
from collections import Counter
from matplotlib import style
style.use('fivethirtyeight')

#traininng data
dataset = {'k': [[1,4],[2,3],[3,1],[2,6],[1,4],[3,7],[3,3],[2,5]], 'r':[[6,5],[7,7],[8,6],[6,5],[6,3],[5,7],[8,6],[5,5]]}

#new data instance
new_data = [2,5]



def knn(data,predict, k=3):
    if len(data) >= k:
        warnings.warn('k is less than total voting group')
    distances = [] 
    
    #getting euclidian distance between data items
    for group in data:
        for features in data[group]:
            euclidian_distance = np.linalg.norm(np.array(features) - np.array(predict))
            distances.append([euclidian_distance, group])
            
    #cumulative votes to determine class    
    votes = [i[1] for i in sorted(distances)[:k]]
    print(Counter(votes).most_common(1))
    vote_result = Counter(votes).most_common(1)[0][0]
        
    return vote_result

result = knn(dataset, new_data, k=3)

print(result)

#plot of new sorted data
[[plt.scatter(ii[0],ii[1], s=50, color=i) for ii in dataset[i]] for i in dataset]
plt.scatter(new_data[0], new_data[1], marker ='*', s=150, color = result)
plt.show()

