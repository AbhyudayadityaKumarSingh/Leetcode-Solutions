class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi = 1 ;
        if(nums.size() == 0) return 0 ;
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                if(nums[j] > nums[j-1]) maxi = max(maxi, j-i+1) ;
                else break ;
            }
            for(int j=i+1; j<nums.size();j++) {
                if(nums[j] < nums[j-1]) maxi = max(maxi,j-i+1) ;
                else break ;
            }
        }
        return maxi ;
    }
};