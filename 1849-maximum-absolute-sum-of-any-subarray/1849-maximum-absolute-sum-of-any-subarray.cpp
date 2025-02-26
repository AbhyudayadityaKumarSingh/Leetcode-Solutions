class Solution {
public:
    pair<int,int> maxSum(vector<int> &nums) {
        int maxi = -1e9 , mini = 1e9 ;
        int sum1 = 0 ,sum2 = 0 ;
        for(int &x : nums) {
            sum1 += x ;
            sum2 += x ;
            maxi=  max(maxi,sum1) ;
            mini = min(mini,sum2) ;
            if(sum2>0) sum2 = 0 ;
            if(sum1 <0) sum1 = 0 ;
        }
        return {maxi,mini};
    }
    int maxAbsoluteSum(vector<int>& nums) {
            int n = nums.size() ;
            pair<int,int> res = maxSum(nums) ;
            int ans = max(abs(res.first),abs(res.second));
            return ans ;
    }
};