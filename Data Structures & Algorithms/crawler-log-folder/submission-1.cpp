class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> st;

        for(auto curr : logs) {
            if(curr == "../") {
                if(!st.empty()) st.pop();
            }
            else if(curr == "./") continue;
            else st.push(curr);
        }

        return st.size();
    }
};