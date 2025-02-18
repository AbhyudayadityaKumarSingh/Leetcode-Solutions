class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st ;
        string ans =  "" ;
        for(char &ch : s) {
            if (st.empty()){
                st.push(ch);
            }
            else {
               
                if(ch == '(') st.push(ch) ;
                else st.pop() ;
                if(!st.empty()) ans.push_back(ch) ;
            }
        }
        return ans ;
    }
};