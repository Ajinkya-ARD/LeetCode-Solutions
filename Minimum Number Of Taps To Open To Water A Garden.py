class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        if n == 0:
            return 0
        
        tap_coverage = [0] * (n + 1)
        
        for i, r in enumerate(ranges):
            lo = max(0, i - r)
            hi = min(i + r, n)
            tap_coverage[lo] = max(tap_coverage[lo], hi)
        
        taps = 1
        start = 0
        next_max = tap_coverage[0]
        
        while start <= next_max:
            if next_max >= n:
                return taps
            
            new_max = 0
            for i in range(start, next_max+1):
                new_max = max(new_max, tap_coverage[i])
        
            if new_max == next_max:
                return -1
            
            taps += 1
            start, next_max = next_max, new_max
        return -1