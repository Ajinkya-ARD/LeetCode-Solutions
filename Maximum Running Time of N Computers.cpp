class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum = 0;
        for(int battery: batteries)
            sum += battery;
        long long l = 0, r = sum/n;
        while(l < r){
            long long mid = l + (r-l)/2 + 1; 
            if(canFit(n, mid, batteries)){
                l = mid;
            }else
                r = mid - 1;
        }
        return l;
    }
    
    long long canFit(int n, long long k, vector<int>& batteries){
        long long target = n * k;
        long long res = 0;
        for(int battery: batteries){
            res += battery < k ? battery : k;
                if(res >= target)
                    return true;
        }
        return res >= target;
    }
};