class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt = 0 ;
        for(int i=0;i<words.size();i++) {
            string word = words[i] ;
            for(int j=0;j<words.size();j++) {
                if(i<j  and words[j].find(word)==0 and words[j].rfind(word) == words[j].size()- word.size()) cnt +=1 ;
            }
        }
        return cnt ;
    }
};