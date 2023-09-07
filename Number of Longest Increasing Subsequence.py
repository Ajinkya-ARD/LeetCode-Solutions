class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 1:
            return n
        dp = [ [0, 0] for i in range(n) ]
        dp[0] = [1, 1]
        for i in range(1, n):
            max_l = 0
            good_k = []
            for j in range(i):
                if nums[j] < nums[i]:
                    if max_l < dp[j][1]:
                        good_k = [ j ]
                        max_l = max(max_l, dp[j][1])
                    elif max_l == dp[j][1]:
                        good_k.append(j)
            if len(good_k) == 0:
                dp[i] = [1, 1]
            else:
                dp[i][1] = max_l + 1
                for k in good_k:
                    dp[i][0] += dp[k][0]
        max_l = 0
        res = 0
        # print(dp)
        for k in range(n):
            if max_l < dp[k][1]:
                max_l = dp[k][1]
                res = dp[k][0]
            elif max_l == dp[k][1]:
                res += dp[k][0]
        return res