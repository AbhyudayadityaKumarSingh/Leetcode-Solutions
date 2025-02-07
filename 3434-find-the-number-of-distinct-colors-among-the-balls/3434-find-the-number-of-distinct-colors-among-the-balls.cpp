class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map <int,int> btc ;
        unordered_map <int,int> ctc ;

        
        vector<int> ans ;
         int cnt = 0 ;
        for(int i=0;i<queries.size();i++) {
            
            int ball = queries[i][0] ;
            int color = queries[i][1] ;
            
            if(btc.find(ball) != btc.end()) {
                int old = btc[ball] ;
                ctc[old] -- ;
                if(ctc[old]==0) cnt -- ;
            }
           btc[ball]= color ;
            ctc[color]++;
            if(ctc[color]==1) cnt ++ ;
            ans.push_back(cnt) ;
            
        }
        return ans ;
    }
};