class Solution {
public:
char findTheDifference(string s, string t) {
        int a[26];
        memset(a,0,sizeof(a));
        int i;
        for(i=0;i<t.length();i++){
            a[t[i]-'a']++;
        }
        for(i=0;i<s.length();i++){
            a[s[i]-'a']--;
        }
        for(i=0;i<26;i++){
            if(a[i]>0)
                return char(i+'a');
        }
        return 'a';
    }
};