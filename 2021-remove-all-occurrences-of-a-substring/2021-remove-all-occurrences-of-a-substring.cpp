class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.size() > 0  and s.find(part) < s.size()) {
            s.erase(s.find(part) , part.size()) ;
        }
        return s ;
     }
};