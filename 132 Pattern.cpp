class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_array(n);
        min_array[0] = nums[0];
        for(int i = 1; i < n; i++) {
            min_array[i] = min(min_array[i-1], nums[i]);
        }
        vector<int> st;
        for(int i = n-1; i >= 0; i--) {
            if(!st.empty() && nums[i] > min_array[i] && nums[i] < st.back() &&
               min_array[i] < st.back()) st.push_back(nums[i]);
            else  if(st.empty()) st.push_back(nums[i]);
            else if(nums[i] == min_array[i]) continue;
            else {
                while(!st.empty() && nums[i] > st.back() && st.back() <= min_array[i]) st.pop_back();
                if(!st.empty() && nums[i] > st.back() && st.back() > min_array[i]) return true;
                else st.push_back(nums[i]);
            }
            
        }
        return false;
    }
};
