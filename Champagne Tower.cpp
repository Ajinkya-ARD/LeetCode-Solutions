class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row + 2, vector<double>(query_glass + 2));
        dp[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= query_glass; j++) {
                
                if (dp[i][j] > 1.0) {

                    double overflow = dp[i][j] - 1.0;

                    dp[i + 1][j] += overflow / 2;
                    dp[i + 1][j + 1] += overflow / 2;
                }
            }
        }
        return min(1.0, dp[query_row][query_glass]);
    }
};