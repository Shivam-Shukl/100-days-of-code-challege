class Solution {
public:
    int minSwaps(string s) {
        stack<char> st ;
        int count = 0  ;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '['){
                st.push(s[i]) ;
            }else{
                if(!st.empty() && st.top() == '[') 
                st.pop() ;
                else 
                st.push(s[i]) ;
            }
        }
        count = st.size() ;
        return ceil(count/4.0) ;
    }
};