class Solution {
public:
    bool search(const vector<int>& nums, int target) {
        for (const auto& i : nums) {
            if (i == target) {
                return true;
            }
        }
        return false;
    }
};
