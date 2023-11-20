class Solution {
public:
     int minimizeMax(vector<int>& Z, int x) {
        sort(Z.begin(), Z.end());
        int n = Z.size(), left = 0, right = Z[n - 1] - Z[0];
        while (left < right) {
            int mid = (left + right) / 2, k = 0;
            for (int i = 1; i < n && k < x; ++i) {
                if (Z[i] - Z[i - 1] <= mid) {
                    k++;
                    i++;
                }
            }
            if (k >= x)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};