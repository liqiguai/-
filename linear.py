import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
from sklearn.datasets import load_boston

boston = load_boston()
X = pd.DataFrame(np.hstack([np.matrix(np.ones(400)).T, np.matrix(boston['data'][0:400])]).T)
X_test = pd.DataFrame(np.hstack([np.matrix(np.ones(106)).T, np.matrix(boston['data'][400:])]).T)
y = boston['target'][0:400]
y_test = boston['target'][400:]
A = np.ones(len(boston['data'][0]) + 1)
s = 0.000001

def costfunc(X, y, A):
    temp = np.zeros(len(A))
    for i in range(len(A)):
        f = 0
        for j in range(len(X.iloc[0])):
            f += X.iloc[i][j] * ((np.matrix(A) * np.matrix(X[j]).T) - y[j])
        f /= len(X.iloc[i])
        temp[i] = A[i] - s * f
    for i in range(len(A)):
        A[i] = temp[i]
        
def predict(X, A):
    y = np.zeros(len(X.iloc[0]))
    for i in range(len(X.iloc[0])):
        y[i] = np.matrix(A) * np.matrix(X[i]).T
    return y

for i in range(20):
    costfunc(X, y, A)

y_pred = predict(X, A)

#plt.plot(range(y_pred.shape[0]), y_test, color = 'blue', linewidth = 1.5, linestyle = '-')
#plt.plot(range(y_pred.shape[0]), y_pred, color = 'red', linewidth = 1.5, linestyle = '-.')
#plt.legend(['test','predict'])

plt.plot(range(y.shape[0]), y, color = 'blue', linewidth = 1.5, linestyle = '-')
plt.plot(range(y.shape[0]), y_pred, color = 'red', linewidth = 1.5, linestyle = '-.')
plt.legend(['test','predict'])