class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char,int>> st;

        for(auto ch : s) {
            if(st.empty()) {
                st.push({ch, 1});
            }
            else if(ch == st.top().first) {
                st.push({ch, st.top().second + 1});
            }
            else {
                st.push({ch, 1});
            }

            if(st.top().second == k) {
                for(int i = 0; i < k; i++) {
                    st.pop();
                }
            }
        }

        string ans = "";

        while(!st.empty()) {
            ans += st.top().first;
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};