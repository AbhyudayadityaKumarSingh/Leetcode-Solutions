class Solution {
public:
    string clearDigits(string s) {
        string result ;
        for(int i=0;i<s.size();i++) {
            if(s[i]>='a' and s[i] <='z') {
                result.push_back(s[i]) ;
            }
            else {
                result.pop_back() ;
            }
        }
        return result ;
    }
};