class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0 , cnt2 = 0 ;
        int ele1 = INT_MAX , ele2 = INT_MAX ;
        for(int i=0;i<nums.size();i+=1) {
            if(cnt1==0 and ele2 != nums[i]) {
                cnt1 = 1 ;
                ele1 = nums[i] ;
            }
            else if(cnt2==0 and ele1!=nums[i]) {
                cnt2 =1 ;
                ele2 = nums[i] ;
            }
            else if(nums[i] == ele1) cnt1 +=1 ;
            else if(nums[i] == ele2) cnt2 +=1 ;
            else {
                cnt1--,cnt2-- ;
            }
        }
        vector<int> ans ;
        int n = nums.size() ;
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++) {
            if(nums[i] == ele1) cnt1 ++ ;
            if(nums[i] == ele2) cnt2++ ;
        }
        if(cnt1 >(n/3)) ans.push_back(ele1) ;
        if(cnt2 > (n/3) ) ans.push_back(ele2) ;
        return ans ;
    }
};