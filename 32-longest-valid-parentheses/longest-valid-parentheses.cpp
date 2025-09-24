class Solution {
public:
    int longestValidParentheses(string s){
        int maxLen = 0;
        stack<int> st;

        st.push(-1);  // base index to handle first valid substring

        for(int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                st.push(i);   // push index of '('
            }
            else {  // when it's ')'
                st.pop();
                if(st.empty()){
                    st.push(i);  // reset base index
                }
                else{
                    maxLen = max(maxLen, i - st.top());  // length of valid substring
                }
            }
        }
        return maxLen;
    }
};

        // int count = 0;

        // for(int i=0;i<s.length();i++){
        //     if(s[i] == '('){
        //         if(s[i+1] == ')'){
        //             count = count + 2;
        //         }
        //     }
        // }

        // return count;