import numpy as np

arr = np.arange(20)
np.random.shuffle(arr)
for i in arr:
    print(i, end=" ")
