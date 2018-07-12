
# coding: utf-8

# In[1]:


import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import somoclu
get_ipython().magic(u'matplotlib inline')

c1 = np.random.rand(50,3)/5
c2 = (0.6, 0.1, 0.05) + np.random.rand(50, 3)/5
c3 = (0.4, 0.1, 0.7) + np.random.rand(50, 3)/5

data = np.float32(np.concatenate((c1, c2, c3)))
colors = ['red'] * 50
colors.extend(['green'] * 50)
colors.extend(['blue'] * 50)
fig = plt.figure()
ax = Axes3D(fig)
ax.scatter(data[:,0], data[:, 1], data[:, 2], c = colors)

#training somoclu
n_rows, n_columns = 100, 160
som = somoclu.Somoclu(n_columns, n_rows, data = data)
get_ipython().magic(u'time som.train()')

som.view_component_planes()

