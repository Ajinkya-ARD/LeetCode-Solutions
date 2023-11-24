class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        string ans="",temp="",res="";
        
        for(int i=0;i<s.length()-1;i++)
        {
            temp+=s[i];
            if(s.length()%temp.length()==0)
            {
                res="";
                for(int j=1;j<=int(s.length()/temp.length());j++)
                    res+=temp;
                if(res==s)
                    return 1;
            }
            
        }
            
        return 0;
    }
};