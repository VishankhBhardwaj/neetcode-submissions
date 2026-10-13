class Solution {
public:
    vector<vector<vector<int>>> dp;

    bool helper(int i, int j, int count, string& s) {
        if (count > 1) return false;
        if (i >= j) return true;

        if (dp[i][j][count] != -1)
            return dp[i][j][count];

        if (s[i] != s[j]) {
            return dp[i][j][count] =
                helper(i + 1, j, count + 1, s) ||
                helper(i, j - 1, count + 1, s);
        }

        return dp[i][j][count] =
            helper(i + 1, j - 1, count, s);
    }

    bool validPalindrome(string s) {
        int n = s.size();

        dp.assign(n, vector<vector<int>>(
            n, vector<int>(2, -1)
        ));

        return helper(0, n - 1, 0, s);
    }
};