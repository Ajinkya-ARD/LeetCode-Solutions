class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    int ans = 0;

    // Sort the array
    sort(begin(nums), end(nums));

    // Use two pointers to generate pairs
    for (int i = 0, j = nums.size() - 1; i < j;) {
      // Update the maximum pair sum for the current pair
      ans = max(ans, nums[i++] + nums[j--]);
    }

    // Return the minimized maximum pair sum
    return ans;
  }
};