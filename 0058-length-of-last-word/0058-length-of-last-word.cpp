class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0 ;
        int i=0;
        for(i=s.size()-1;i>=0;i--) {
            if(s[i] != ' ') break ;
           
        }
        for(int j=i;j>=0;j--) {
            if(s[j] == ' ') break ;
            else len +=1 ;
        }
        return len ;
    }
};