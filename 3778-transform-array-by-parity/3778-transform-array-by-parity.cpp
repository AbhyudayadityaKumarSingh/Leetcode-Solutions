class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
       
        int n = nums.size() ;
        for(int i=0;i<n;i++) {
            if(nums[i] % 2 == 0) nums[i] = 0 ;
            else nums[i] = 1 ;
        }
        sort(begin(nums),end(nums)) ;
        return nums ;
    }
};