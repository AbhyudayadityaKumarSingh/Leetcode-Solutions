class Solution {
public:
    string largestOddNumber(string num) {
        string ans ="" ;
       int index = -1 ;
        for(int i=num.size()-1;i>=0;i--) {
             int a = num[i] - '0' ;
             if(a&1==1) {
                index = i ;
                break ;
             }
        }
        for(int i=0;i<=index;i++) {
            ans.push_back(num[i]) ;
        }
       
        return ans ;
    }
};