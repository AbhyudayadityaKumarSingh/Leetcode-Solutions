class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map <int,int>  mp ; // id -> value
        for(auto &x : nums1) {
            int id = x[0] ;
            int val = x[1] ;
            mp[id] = val ;
        }
        for(auto &x : nums2) {
            int id = x[0] ;
            int val = x[1] ;
            if(mp.find(id) != mp.end()) {
                mp[id] += val ;
            }
            else mp[id] = val ;
        }

        vector<vector<int>> ans ;
        for(auto &it : mp) {
            ans.push_back({it.first,it.second}) ;
        }
        return ans ;
    }
};