class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res, all;
        int n = groupSizes.size();
        for (int i = 0; i < n; ++i) {
            all.push_back({groupSizes[i], i});
        }
        sort(all.begin(), all.end());
        for (int i = 0; i < n; ++i) {
            int cnt = all[i][0];
            vector<int> out;
            for (int j = 0; j < cnt; ++j) {
                out.push_back(all[i + j][1]);
            }
            res.push_back(out);
            i += cnt - 1;
        }
        return res;
    }
};