
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.size();
        int m = abbr.size();

        int i = 0, j = 0;

        while (i < n && j < m) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0') return false;

                int k = j;
                while (k < m && isdigit(abbr[k])) {
                    k++;
                }

                string temp = abbr.substr(j, k - j);
                int num = stoi(temp);

                i += num;
                j = k;
            }
            else {
                if (i >= n || word[i] != abbr[j])
                    return false;

                i++;
                j++;
            }
        }

        return i == n && j == m;
    }
};
