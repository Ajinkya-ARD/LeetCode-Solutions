class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0;
        int f_ocr=-1,l_ocr=-1;
        int l = nums.size()-1;
        //first occurence --->
        while(s<=l){
            int mid = s + (l-s)/2;
            if(target==nums[mid])
            {
                f_ocr = mid;
                l = mid-1;
            }
            else if(target>nums[mid]){
                s = mid+1;
            }
            else l = mid-1;
        }
        s=0;l=nums.size()-1;
        //last occurance --->
        while(s<=l){
            int mid = s + (l-s)/2;
            if(target==nums[mid])
            {
                l_ocr = mid;
                s = mid+1;
            }
            else if(target<nums[mid]){
                l = mid-1;
            }
            else s = mid+1;
        }
       if(f_ocr==-1)return {-1,-1};
        else return {f_ocr,l_ocr};
    }
};