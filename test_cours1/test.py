import sys, random
from time import *

N = 2048

A = [[random.random()
      for row in range(N)]
      for col in range(N)]
B = [[random.random()
      for row in range(N)]
      for col in range(N)]

C = [[0 for row in range(N)]
      for col in range(N)]

start = time()
for i in range(N):
    for j in range(N):
        for k in range(N):
            C[i][j] += A[i][k] * B[k][j]
end = time()

print(end - start)