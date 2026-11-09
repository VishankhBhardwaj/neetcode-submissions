class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        for (auto ch : s) {
            if (ch == ')') {
                string temp = "";
                while(st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                for(int i=0;i<temp.size();i++){
                    st.push(temp[i]);
                }
            }
            else st.push(ch);
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};