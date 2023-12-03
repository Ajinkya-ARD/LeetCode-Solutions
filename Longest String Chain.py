class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        res = 0
        dp = {}
        words.sort(key=len)
        
        for word in words:
            # break down every substring, find if it exist in map already
            # in map: 1+dp[substring]
            # not in map: ignore
            dp[word] = 1
            for i in range(len(word)):
                substring = word[:i]+word[i+1:]
                # dp[word] = max(dp[word], dp.get(substring, 0)+1)
                if substring in dp:
                    dp[word] = max(dp[word], 1+dp[substring])
            res = max(res, dp[word])
        return res