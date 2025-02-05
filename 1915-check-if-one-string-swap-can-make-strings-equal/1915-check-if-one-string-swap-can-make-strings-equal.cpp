class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        map <char,int> mp1 ;
        map <char,int> mp2 ;
        for(char &ch : s1) {
            mp1[ch] ++ ;
        }
        for(char &ch : s2) {
            mp2[ch] ++ ;
        }
        for(auto &it : mp1) {
            if(mp2.find(it.first) == mp2.end()) return false ;
            else {
                 if(mp2[it.first] != mp1[it.first]) return false ;
                
            }
        }

        int cnt = 0 ;
        for(int i=0;i<s1.size();i++) {
            if(s1[i] != s2[i]) cnt++ ;
        }
        if(cnt >2 ) return false ;
        return true ;
    }
};