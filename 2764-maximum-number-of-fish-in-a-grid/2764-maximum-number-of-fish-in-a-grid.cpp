class Solution {
public:
   
    int dfs(vector<vector<int>>& grid, int row , int col ,int m , int n ) {
       if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0) {
            return 0;
        }
        int take = grid[row][col] ;
        grid[row][col] = 0 ;
        int delrow[] = {0,-1,0,1} ;
        int delcol[] = {-1,0,1,0} ;

        for(int i=0;i<4;i++) {
            int nrow = row + delrow[i] ;
            int ncol = col + delcol[i] ;

            take += dfs(grid,nrow,ncol,m,n) ;
        }
        return take ;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int maxi = 0 ;
        int m = grid.size() ;
        int n = grid[0].size() ;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] >0 ) maxi = max(maxi,dfs(grid,i,j,m,n)) ;
            }
        }
        
        return maxi ;
    }
};