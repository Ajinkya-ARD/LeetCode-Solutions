class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        length = len(nums)
        total = 0
        freq_map = {}
        for i in range(length):
            if nums[i] not in freq_map:
                freq_map[nums[i]] = 1
            else:
                freq_map[nums[i]] += 1
        for key,value in freq_map.items():
            total += (value * ( value -1) //2)
            
        return total
