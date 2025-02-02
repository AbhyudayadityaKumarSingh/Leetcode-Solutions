class Solution {
public:
   int m ,n ;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& board, int row, int col,vector<vector<bool>> &vis ){
       if (row < 0 || row >= m || col < 0 || col >= n || board[row][col] == 'X' || vis[row][col] == true) 
            return;
        vis[row][col] = true ;
        for(auto &vec : directions) {
            int nrow = row + vec[0] ;
            int ncol = col + vec[1] ;

              if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && board[nrow][ncol] == 'O' && !vis[nrow][ncol]) 
                dfs(board, nrow, ncol, vis);
        }    
    }
    void solve(vector<vector<char>>& board) {
         m = board.size() ;
         n = board[0].size() ;

        vector<vector<bool>> vis(m, vector<bool>(n,false) ) ;

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) dfs(board, 0, j, vis);
            if (board[m - 1][j] == 'O' && !vis[m - 1][j]) dfs(board, m - 1, j, vis);
        }
         for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O' && !vis[i][0]) dfs(board, i, 0, vis);
            if (board[i][n - 1] == 'O' && !vis[i][n - 1]) dfs(board, i, n - 1, vis);
        }

         int cnt = 0 ;
         for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && board[i][j] == 'O') 
                    board[i][j] = 'X';
            }
        }
    }
};