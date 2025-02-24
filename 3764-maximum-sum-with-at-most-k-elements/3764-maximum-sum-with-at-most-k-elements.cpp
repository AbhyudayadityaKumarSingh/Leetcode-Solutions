class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int m = grid.size() ;
        int n =  grid[0].size() ;
        priority_queue<int> pq ;
        for(int i=0;i<m;i++) {
            sort(grid[i].rbegin(), grid[i].rend());
        }
        for(int i=0;i<m;i++) {
            int limit = min(n,limits[i]) ;
            for(int j=0;j<limit;j++) {
                pq.push(grid[i][j]) ;
            }
        }
        
        long long sum = 0 ;
        while(k-- and !pq.empty()) {
            sum += pq.top() ;
            pq.pop() ;
        }
        return sum ;
    }
};