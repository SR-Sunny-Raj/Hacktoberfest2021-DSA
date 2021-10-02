import numpy as np
from itertools import combinationsdef TSP(G):
   n = len(G)
   C = [[np.inf for _ in range(n)] for __ in range(1 << n)]
   C[1][0] = 0 # {0} <-> 1
   for size in range(1, n):
      for S in combinations(range(1, n), size):
	  S = (0,) + S
	  k = sum([1 << i for i in S])
	  for i in S:
	      if i == 0: continue
	      for j in S:
		 if j == i: continue
		    cur_index = k ^ (1 << i)
		    C[k][i] = min(C[k][i], C[cur_index][j]+ G[j][i])     
		                                       #C[S−{i}][j]
   all_index = (1 << n) - 1
   return min([(C[all_index][i] + G[0][i], i) \
                            for i in range(n)])
