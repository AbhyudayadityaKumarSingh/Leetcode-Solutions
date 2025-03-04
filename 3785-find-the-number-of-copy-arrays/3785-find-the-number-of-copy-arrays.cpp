class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size();
        if(n==0) {
            return 0 ;
        }
        vector<int> diffs ;
        for(int i=1;i<n;i++) {
            diffs.push_back(original[i]-original[i-1]) ;
        }
        int low = bounds[0][0];
        int high = bounds[0][1];
        int sum_diffs = 0;
        for(int i=1;i<n;i++) {
             sum_diffs += diffs[i - 1];
             int new_low = bounds[i][0] - sum_diffs;
            int new_high = bounds[i][1] - sum_diffs;
            
             low = max(low, new_low);
            high = min(high, new_high);
             if (low > high) {
                return 0;
            }
        }
        
        return high-low+1 ;
    }
};