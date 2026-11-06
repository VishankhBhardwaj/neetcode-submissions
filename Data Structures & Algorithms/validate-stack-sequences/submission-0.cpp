class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int i = 0;
        int j = 0;
        stack<int>st;
        while(i<n){
            st.push(pushed[i]);
            while(!st.empty() && popped[j] == st.top()){
                st.pop();
                j++;
            }
            i++;
        }
        return j == n;
    }
};
