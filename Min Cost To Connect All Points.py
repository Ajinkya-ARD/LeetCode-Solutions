class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        root = [i for i in range(n)]
        rank = [1] * n
        
        def find(x):
            if x != root[x]:    
                root[x] = find(root[x])
            return root[x]
        
        def union(x, y):
            rtx = find(x)
            rty = find(y)
            if rtx == rty: return False
            rkx = rank[rtx]
            rky = rank[rty]
            if rkx > rky:
                root[rty] = rtx
            elif rkx < rky:
                root[rtx] = rty
            else:
                root[rty] = rtx
                rank[rtx] += 1
            return True
        
        def dis(px, py):
            return abs(px[0] - py[0]) + abs(px[1] - py[1])
        
        dis_pq = []
        for i in range(n-1):
            for j in range(i+1, n):
                dis_pq.append((dis(points[i], points[j]), i, j)) # put all edges
                
        heapq.heapify(dis_pq)
        res = 0
        while n - 1 > 0:
            cur_dis, i, j = heapq.heappop(dis_pq)
            if union(i, j): # if can connect, means not already connected, not a cycle
                res += cur_dis
                n -= 1
            
        return res