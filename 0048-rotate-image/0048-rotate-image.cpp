class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size() ;
        int n = matrix[0].size() ;
        // Step 1 : Transpose the matrix
        for(int i=0;i<m;i++) {
            for(int j=i+1;j<n;j++) {
                swap(matrix[i][j] ,matrix[j][i]) ;
            }
        }
        // Step2 : Reverse each row
        int i = 0 ;
        while(i<n) {
            int j = 0 , k= m-1 ;
            while(j<=k){
                swap(matrix[i][j] , matrix[i][k]) ;
                j++,k-- ;
            } 
            i+=1 ;
        }
    }
};