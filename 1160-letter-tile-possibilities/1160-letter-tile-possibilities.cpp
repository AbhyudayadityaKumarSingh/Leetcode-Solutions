class Solution {
public:
    int n ;
    
    void solve(string& tiles, string&temp ,unordered_set<string> &ans, vector<bool>& used ) {
        ans.insert(temp) ;
        for(int i=0;i<n;i++) {
            if(used[i]) continue ;
            temp.push_back(tiles[i]) ;
            used[i] = true ;
            solve(tiles,temp,ans,used) ;
            used[i] = false ;
            temp.pop_back() ;
        }
    }
    int numTilePossibilities(string tiles) {
        n = tiles.size() ;
        vector<bool> used(n,false) ;
  
        unordered_set<string> ans;
        string temp = "" ;
        solve(tiles,temp,ans,used) ;
        return ans.size()-1 ;
    }
};