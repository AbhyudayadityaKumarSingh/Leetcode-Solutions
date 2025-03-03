class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> lesser ; 
        vector<int> greater ;
        int cnt = 0 ;
        for(int &x : nums) {
            if(x < pivot) lesser.push_back(x) ;
            else if(x > pivot) greater.push_back(x) ;
            else cnt ++ ;
        }
        vector<int> ans ;
        for(int &x : lesser) {
            ans.push_back(x) ;
        }
        while(cnt--) {
             ans.push_back(pivot) ;
        }
        for(int &x : greater) {
            ans.push_back(x) ;
        }
        return ans ;
    }
};