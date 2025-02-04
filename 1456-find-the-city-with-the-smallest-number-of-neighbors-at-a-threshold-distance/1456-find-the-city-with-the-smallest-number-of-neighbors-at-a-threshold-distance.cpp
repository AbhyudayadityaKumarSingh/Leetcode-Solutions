class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> mat(n,vector<int>(n,INT_MAX)) ;
        for(auto &edge : edges) {
            int u = edge[0] , v = edge[1] , wt = edge[2] ;
            mat[u][v] = wt ;
            mat[v][u] = wt ;
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) if(i==j) mat[i][i] = 0 ;
        }

        for(int via=0;via<n;via++ ) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if (mat[i][via] != INT_MAX && mat[via][j] != INT_MAX) {
                        mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                    }
                }
            }
        }

        int ans = 0 ;
        int mini = 1e9 ;
        for(int i=0;i<n;i++) {
            int cnt = 0 ;
            for(int j=0;j<n;j++) {
               if(mat[i][j] <= distanceThreshold) cnt ++ ;
            }
            if(cnt <= mini) {
                mini = cnt ;
                ans = i ;
            }
        }
        return ans ;
    }
};