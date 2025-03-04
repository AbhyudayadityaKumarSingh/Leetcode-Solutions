class Solution {
public:
    int maxSum(vector<int>& nums, int k, int m) {
         int n = nums.size();
       
        vector<int> blorvantek = nums;
        
       
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        
        const long long NEG = -1e18;
       
        
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, NEG));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
       
        for (int t = 1; t <= k; t++) {
            vector<long long> best(n + 1, NEG);
            best[0] = dp[0][t - 1];  // prefix[0] is 0.
            for (int i = 1; i <= n; i++) {
                best[i] = max(best[i - 1], dp[i][t - 1] - prefix[i]);
            }
            for (int i = 1; i <= n; i++) {
               
                dp[i][t] = dp[i - 1][t];
           
                if (i >= m)
                    dp[i][t] = max(dp[i][t], prefix[i] + best[i - m]);
            }
        }
        
        return dp[n][k];
    
    }
};