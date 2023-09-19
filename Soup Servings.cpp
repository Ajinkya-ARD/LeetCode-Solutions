class Solution {
    public: 
    double soupServings(int n) {
      if (n>10000)
        return 1;
      vector<vector<double>>memo(400,vector<double>(400,0.0));
      return solve((n+24)/25,(n+24)/25,memo);    
    }
    double solve(int a, int b, vector<vector<double>>&memo){
        if(a<=0&&b<=0){
            return 0.5;
        }
        if(a<=0){
            return 1.0;
        }
        if(b<=0){
            return 0.0;
        }
        if(memo[a][b]>0)
            return memo[a][b];
        
        memo[a][b]=0.25*(solve(a-4,b,memo)+solve(a-3,b-1,memo)+solve(a-2,b-2,memo)+solve(a-1,b-3,memo));
        return memo[a][b];
          
    }

};