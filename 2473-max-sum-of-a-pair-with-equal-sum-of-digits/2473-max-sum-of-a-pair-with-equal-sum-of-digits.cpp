class Solution {
public:
    int sumofDig(int num) {
        int ans = 0 ;
        while(num!=0) {
            int dig = num%10 ;
            ans += dig ;
            num/=10;
        }
        return ans ;
    }
    int maximumSum(vector<int>& nums) {
        vector<pair<int,int>> digitSum ;
        int n = nums.size() ;
        for(int i=0;i<n;i++) {
            int sum = sumofDig(nums[i]) ;
            digitSum.push_back({sum,nums[i]}) ;
        }
        sort(digitSum.begin() , digitSum.end()) ;

        int maxi = -1;
        for(int i=1;i<digitSum.size();i++) {
            int currsum = digitSum[i].first ;
            int prevsum = digitSum[i-1].first ;

            if(prevsum == currsum) {
                maxi = max(maxi, digitSum[i].second + digitSum[i-1].second) ;
            }
        }
        return maxi ;
    }
};