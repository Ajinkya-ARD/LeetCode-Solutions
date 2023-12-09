class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    // Initialize the array with 1's
    vector<int> ans(rowIndex + 1, 1);
    // Starting from third index
    for (int i = 2; i <= rowIndex; ++i)
      // For each i from 1 to i-1
      for (int j = i - 1; j > 0; --j)
        // Update ans[j] by the sum of ans[j] and ans[j-1]
        ans[j] += ans[j - 1];
    return ans;
  }
};