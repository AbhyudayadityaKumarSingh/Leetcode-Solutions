class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi = 0 ;
        for(int i=0;i<nums.size();i++) {
            int sum = nums[i] ;
            for(int j=i+1;j<nums.size();j++) {
                if(nums[j] > nums[j-1]) sum += nums[j] ;
                else break ;
            }
            maxi = max(maxi,sum) ;
        }
        return maxi ;
    }
};