class Solution {
public:
    string findValidPair(string s) {
        map <int,int> mp ;
        for(char &ch : s) {
            mp[ch-'0'] ++ ;
        }
        
        string valid = "" ;
        for(int i=1;i<s.size();i++) {
            if(s[i] != s[i-1] ) {
                 if((mp[s[i]-'0'] == s[i]-'0') and ((mp[s[i-1]-'0'] == s[i-1]-'0'))) {
                     valid += s[i-1] ;
                     valid+= s[i] ;
                     break ;
                 }
                
            }
        }
        return valid ;
    }
};