class Solution {
public:
    void sortColors(vector<int>& nums) {
        int one = 0 , zero = 0 , two = 0 ;
        for(int &x : nums) {
            if(x==0) zero ++ ;
            else if(x == 1) one +=1 ;
            else two +=1 ;
        }
        int i = 0 ;
        while(zero>0) {
            nums[i] = 0 ;
            i++ ;
            zero-- ;
        }
        while(one>0) {
            nums[i] = 1 ;
            i++ ;

            one-- ;
        }
        while(two>0) {
            nums[i] = 2 ;
            i++ ;

            two-- ;
        }
    }
};