class Solution:
    def reorganizeString(self, s: str) -> str:
        dic = [0]*26
        for c in s:
            dic[ord(c) - ord('a')] += 1

        char_heap = []
        for i, freq in enumerate(dic):
            if freq > 0:
                heapq.heappush(char_heap, (-1*freq, chr(ord('a') + i)))
    
        res =[]
        while len(char_heap) > 1:
            one = heapq.heappop(char_heap)
            two = heapq.heappop(char_heap)

            res.append(one[1])
            res.append(two[1])

            if one[0]+1 < 0:
                heapq.heappush(char_heap, (one[0]+1, one[1]))
            if two[0]+1 < 0:
                heapq.heappush(char_heap, (two[0]+1, two[1]))
        
        if len(char_heap) == 1:
            if char_heap[0][0] == -1:
                res.append(char_heap[0][1])
            else:
                return ""
        return ''.join(res)
    
