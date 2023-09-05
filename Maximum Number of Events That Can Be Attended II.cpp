class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        function<int(int, int)> dfs = [&](int i, int j){
            if (i == n || j == 0) return 0;
            if (dp[i][j] != -1)
                return dp[i][j];
            auto k = upper_bound(events.begin() + i, events.end(), events[i][1], [](int val, const vector<int>& it){
                return it[0] > val; 
            }) - events.begin();
            return dp[i][j] = max(dfs(k, j - 1) + events[i][2], dfs(i + 1, j));
        };
        return dfs(0, k);
    }
};