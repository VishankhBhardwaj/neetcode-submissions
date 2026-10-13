class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;

        while (i <= j) {
            char a = tolower(s[i]);
            char b = tolower(s[j]);

            if (!isalnum(a)) {
                i++;
            }
            else if (!isalnum(b)) {
                j--;
            }
            else {
                if (a != b) return false;
                i++;
                j--;
            }
        }
        return true;
    }
};