class Solution {
public:
    string frequencySort(string s) {
      vector<pair<char, int>> freq(128, {0, 0});

       for(int i=0;i<s.size();i+=1) {
         char ch = s[i] ;
         freq[ch].first = ch ;
         freq[ch].second +=1 ;
       }
       auto lambda =[&] (const pair<char, int>& a, const pair<char, int>& b) { 
           return a.second > b.second ;
       };
       sort(freq.begin() , freq.end() , lambda) ;
        string ans = "" ;

        for(auto &it : freq) {
         if (it.second > 0) { // Add only characters with non-zero frequency
                ans += string(it.second, it.first);
            }
        }
        return ans ;
    }
};