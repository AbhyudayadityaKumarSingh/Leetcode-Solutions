class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = -1 ;
        int cnt = 0 ;
        int n = nums.size() ;
        for(int i=0;i<n;i++) {
            if(cnt == 0) {
                ele = nums[i] ;
                cnt =1 ;
            }
            else if(nums[i] == ele) {
                cnt +=1 ;
            }
            else {
                cnt -- ;
            }
        }
        int res =  0 ;
        for(int i=0;i<n;i++) {
            if(nums[i] == ele) res +=1 ;
        }
        if(res > (n/2) ) return ele ;
        return -1 ; 
    }
};