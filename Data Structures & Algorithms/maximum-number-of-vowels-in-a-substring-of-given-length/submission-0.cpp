class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int i = 0;
        string arr = "aeiou";
        int cnt = 0;
        int maxi = 0;

        for (int j = 0; j < n; j++) {
            if (arr.find(s[j]) != string::npos)
                cnt++;

            while (j - i + 1 > k) {
                if (arr.find(s[i]) != string::npos)
                    cnt--;
                i++;
            }

            if (j - i + 1 == k)
                maxi = max(maxi, cnt);
        }

        return maxi;
    }
};