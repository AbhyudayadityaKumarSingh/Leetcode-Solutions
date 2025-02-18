class Solution {
public:
    int n ;
    bool check(string pattern , string ans) {
        for(int i=0;i<n;i++) {
            if((pattern[i]=='I' and ans[i] > ans[i+1]) || (pattern[i]=='D' and ans[i]<ans[i+1])) {
                return false ;
            }
        }
        return true ;
    }
    string smallestNumber(string pattern) {
        n = pattern.size() ;
        string ans = "" ;
        for(int i=1;i<=n+1;i++) {
             ans.push_back(i+'0') ;
        }

        while(!check(pattern,ans)) {
             next_permutation(begin(ans),end(ans)) ;
        }
        return ans ;
    }
};