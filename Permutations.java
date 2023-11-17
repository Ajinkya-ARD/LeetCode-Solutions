class Solution {
    
    public void swap(int[] nums, int i, int j){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
    public void allPermutation(int[] nums, List<List<Integer>> ans, int index){
        if(index >= nums.length){
            List<Integer> a = new ArrayList<>();
            for(int e : nums){
                a.add(e);
            }
            ans.add(a);
            return;
        }
        
        for(int i=index; i<nums.length ;i++){
            swap(nums,index,i);
            allPermutation(nums,ans,index+1);
            swap(nums,index,i);
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        allPermutation(nums,ans,0);
        return ans;
    }
}