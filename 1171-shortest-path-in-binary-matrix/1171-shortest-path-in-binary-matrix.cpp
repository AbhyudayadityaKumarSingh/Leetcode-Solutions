class Solution {
public:
    vector<vector<int>> directions{{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        if (m == 0 || n == 0 || grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return -1;
        queue <pair<int,int>> q ;
        auto isSafe =[&](int x , int y) {
            return x>=0 && x<m && y>=0 && y<n;
        } ;
       
        q.push({0,0}) ;
        grid[0][0] = 1 ;
        int cnt = 1;
        while(!q.empty()) {
            int size = q.size() ;
            while(size--) {
                int x = q.front().first ;
                int y = q.front().second ;
                q.pop() ;

                if(x==m-1 and y==n-1) return cnt ;

                for(auto &dir : directions) {
                    int newx = x + dir[0] ;
                    int newy = y + dir[1] ;
                    if(isSafe(newx,newy) and grid[newx][newy] == 0) {
                        q.push({newx,newy}) ;
                        grid[newx][newy] = 1 ;
                    }
                }
            }
            cnt ++ ;
        }
        return -1 ;
    }
};