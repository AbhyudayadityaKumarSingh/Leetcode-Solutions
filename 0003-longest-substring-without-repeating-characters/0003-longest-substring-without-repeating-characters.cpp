class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp ;
        int n = s.size() ;
        int left = 0 , right = 0 ;
        int maxi = 0 ;
        while(right < n) {
        
         mp[s[right]] ++ ;
         while(mp[s[right]] > 1) {
            mp[s[left]] -- ;
            left++ ;
         }

        maxi = max(maxi,right-left+1) ;
         right++ ;
        }
        return maxi ;
    }
};