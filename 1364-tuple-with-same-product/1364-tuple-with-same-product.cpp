class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map <int,int> mp ;
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                int pro = nums[i]*nums[j] ;
                mp[pro] ++ ;
            }
        }
        int result = 0 ;
        for(auto &entry : mp) {
            int cnt = entry.second ;
            if(cnt > 1) result += cnt*(cnt-1)*4 ;        }
            return result ;
    }
};