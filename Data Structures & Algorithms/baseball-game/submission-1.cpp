class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(auto curr : operations) {
            if(curr == "+") {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                st.push(b);
                st.push(a);
                st.push(a+b);
            }
            else if(curr == "D") {
                st.push(st.top()*2);
            }
            else if(curr == "C") {
                st.pop();
            }
            else {
                st.push(stoi(curr));
            }
        }

        int ans = 0;
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};