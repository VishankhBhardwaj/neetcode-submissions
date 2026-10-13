class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string ans = "";
        int i = 0;

        while (i < n) {
            char ch = chars[i];
            int cnt = 0;

            while (i < n && chars[i] == ch) {
                cnt++;
                i++;
            }

            ans.push_back(ch);

            if (cnt > 1) {
                ans += to_string(cnt);
            }
        }

        for (int k = 0; k < ans.size(); k++) {
            chars[k] = ans[k];
        }

        return ans.size();
    }
};