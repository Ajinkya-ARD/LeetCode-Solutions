class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int,set<int>>mp;
        map<int,int>mp2;
        for(int i=0;i<stones.size();i++)
        {
           mp[stones[i]].insert(0);
        }
        mp[0].insert(1);
        for(int i=0;i<stones.size();i++)
        {
            set<int>vc = mp[stones[i]];
            set<int>::iterator it = vc.begin();
            while(it != vc.end())
            {
                int steps = (*it);
                if(steps != 0 )
                {
                   if(mp2[steps] == 0){
                mp[stones[i]+steps].insert(steps-1);
                 
                mp[stones[i]+steps].insert(steps);
                    
                mp[stones[i]+steps].insert(steps+1);
                       mp2[steps]++;
                   }
                }
                it++;
                
            }
            mp2.clear();
            
            
        }
         int n = stones.size();
        set<int>ans2 = mp[stones[n-1]];
        if(ans2.size()==1)return false;
        return true;
        
        
    }
};