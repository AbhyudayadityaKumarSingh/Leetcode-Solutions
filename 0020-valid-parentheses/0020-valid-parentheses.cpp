class Solution {
public:
    bool isValid(string s) {
        stack <char> st ;
        for(int i=0; i<s.size(); i++) {
            char ele = s[i] ;

            if(ele == '(' or ele == '{' or ele == '[') {
                st.push(ele) ;
            }
            else {
                if(!st.empty()) {
                if( (st.top() == '(' and ele==')') or 
                (st.top() == '{' and ele == '}') or 
                (st.top() == '[' and ele == ']')) {
                    st.pop() ;
                }
                else {
                    return false ;
                }
                }
                else {
                    return false ;
                }
            }
        }

         return st.empty() ;
    }
};