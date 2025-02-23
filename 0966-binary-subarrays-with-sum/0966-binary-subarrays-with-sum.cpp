class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map <int,int> mp ;
        mp[0] = 1 ;
        int sum = 0 ;
        int cnt = 0 ;
        for(int &x : nums) {
            sum += x ;
             if (mp.find(sum - goal) != mp.end()) {
                cnt += mp[sum - goal];
            }
            mp[sum] ++ ;
        } 
        return cnt ;  
    }
};