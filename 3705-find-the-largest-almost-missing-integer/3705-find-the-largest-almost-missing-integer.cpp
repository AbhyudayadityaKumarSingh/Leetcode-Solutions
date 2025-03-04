class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
         int n = nums.size();
        unordered_map<int, int> countMap;
        
       
        for (int i = 0; i <= n - k; ++i) {
            vector<int> subarray(nums.begin() + i, nums.begin() + i + k);
            
            unordered_map<int, bool> seen;
            for (int num : subarray) {
                if (!seen[num]) {
                    countMap[num]++;
                    seen[num] = true;
                }
            }
        }
        
        int maxAlmostMissing = -1;
        for (auto& pair : countMap) {
            if (pair.second == 1) {
                maxAlmostMissing = max(maxAlmostMissing, pair.first);
            }
        }
        
        return maxAlmostMissing;

        
    }
};