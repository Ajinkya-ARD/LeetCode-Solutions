class Solution:
    def minOperations(self, string: str) -> int:
        # Count the number of characters that do not match the pattern '01' repeated.
        # '01'[i & 1] generates '0' for even i and '1' for odd i, which is the expected pattern.
        mismatch_count = sum(char != '01'[index % 2] for index, char in enumerate(string))
      
        # Since there are only two possible patterns ('01' repeated or '10' repeated),
        # if mismatch_count is the cost of converting to pattern '01',
        # then len(string) - mismatch_count will be the cost of converting to pattern '10'.
        # We choose the minimum of these two costs as our result.
        return min(mismatch_count, len(string) - mismatch_count)