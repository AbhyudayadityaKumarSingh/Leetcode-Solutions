class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Dutch national flag algorithm ;
        int low = 0 , mid = 0 , high = nums.size() -1 ;
        while(mid<=high) {
            if(nums[mid] == 0) {
                swap(nums[low] , nums[mid]) ;
                mid ++ ;
                low ++ ;
            }
            else if(nums[mid] ==2 ) {
                swap(nums[high] , nums[mid]) ;
                high -- ;
            }
            else {
                mid +=1 ;
            }
        } 
    }
};