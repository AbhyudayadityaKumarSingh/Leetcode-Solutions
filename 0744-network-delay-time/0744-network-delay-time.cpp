class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map <int , vector<pair<int,int>>> adj ;
        for(auto &it : times) {
            int u = it[0] ;
            int v = it[1] ;
            int time = it[2] ;
            adj[u].push_back({v,time}) ;
        }
        priority_queue <pair<int,int> ,vector<pair<int,int>> , greater<pair<int,int>>> pq ;
        pq.push({0,k}) ;
        vector<int> result(n+1, INT_MAX) ;
        result[k] = 0 ;

        while(!pq.empty()) {
            int node = pq.top().second;
            int dist = pq.top().first ;
            pq.pop() ;
            for(auto &it : adj[node]) {
                int dist_n = it.second ;
                int neighbor = it.first ;
                if(dist+dist_n < result[neighbor]) {
                    result[neighbor] = dist+ dist_n ;
                    pq.push({dist+dist_n , neighbor}) ;
                }
            }
        }
        int ans = INT_MIN ;
        for(int i=1;i<=n;i++) {
            ans = max(ans, result[i]) ;
        }
       
	return ans == INT_MAX ? -1 : ans;
    }
};