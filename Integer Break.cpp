class Solution {
public:
    map<int,int>mp;    
    int integerBreak(int n) {
        mp[1]=1;   
        if(mp.find(n)!=mp.end())
            return mp[n];
        int mx=INT_MIN;
        for(int i=1;i<=n/2;i++)
            mx=max(mx,max(i,integerBreak(i))*max(n-i,integerBreak(n-i)));
        mp[n]=mx;
        return mx;
    }
};