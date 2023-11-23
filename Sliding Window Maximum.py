class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        indices = collections.deque()
        ans = []
        for i in range(len(nums)):
            while indices and nums[i] >= nums[indices[-1]]: indices.pop()
            indices.append(i)
            if i >= k - 1: ans.append(nums[indices[0]])
            if i - k + 1 == indices[0]: indices.popleft()
        return ans