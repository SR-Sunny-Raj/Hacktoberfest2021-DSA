class Solution:
    def reachableNodes(self, edges, M, N):
        G = defaultdict(set)
        dist = [float('inf')] * N
        dist[0] = 0
        
        for i, j, w in edges:
            G[i].add((j, w + 1))
            G[j].add((i, w + 1))
            
        heap = [(0, 0)]

        while heap:
            min_dist, idx = heappop(heap)
            for neibh, weight in G[idx]:
                cand = min_dist + weight
                if cand < dist[neibh]:
                    dist[neibh] = cand
                    heappush(heap, (cand, neibh)) 
                    
        ans = sum(dist[i] <= M for i in range(N))
 
        for i, j, w in edges:
            w1, w2 = M - dist[i], M - dist[j]
            ans += (max(0, w1) + max(0, w2))
            if w1 >= 0 and w2 >= 0: ans -= max(w1 + w2 - w, 0)
                
        return ans
