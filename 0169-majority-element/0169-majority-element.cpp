class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map <int,int> mp ;
        for(int &x : nums) {
            mp[x] ++ ;
        }

        int n =  nums.size() ;
        for(auto &it : mp) {
            if(it.second > n/2) return it.first ;
        }
        return -1;
    }
};