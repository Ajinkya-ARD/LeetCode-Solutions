class Solution {
public:
    int helper(vector<vector<int>>& pairs, int last_i, int i, vector<vector<int>>& dp) {
        if (i == pairs.size()) return 0;

        if (dp[last_i][i] != -1) return dp[last_i][i];

        int a = pairs[last_i][0];
        int b = pairs[last_i][1];
        int c = pairs[i][0];
        int d = pairs[i][1];

        if (b < c) {
            return dp[last_i][i] = max(1 + helper(pairs, i, i+1, dp), helper(pairs, last_i, i+1, dp));
        }

        return dp[last_i][i] = helper(pairs, last_i, i+1, dp);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
   
        vector<int> dp(n, 1);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int mx = 0;
            for (int j = i-1; j >= 0; j--) {
                int a = pairs[j][0];
                int b = pairs[j][1];
                int c = pairs[i][0];
                int d = pairs[i][1];

                if (b < c) {
                    mx = max(mx, 1 + dp[j]);
                }
            }
            dp[i] = max(dp[i], mx);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};