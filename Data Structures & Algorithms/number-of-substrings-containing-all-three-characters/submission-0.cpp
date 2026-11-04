class Solution {
public:
    int helper(string&s,int k){
        int n = s.size();
        unordered_map<char,int>mpp;
        int cnt = 0;
        int i = 0;
        for(int j=0;j<n;j++){
            mpp[s[j]]++;
            while(i<j && mpp.size()>k){
                mpp[s[i]]--;
                if(mpp[s[i]] == 0) mpp.erase(s[i]);
                i++;
            }
            cnt+=j-i+1;
        }
        return cnt;
    }
    int numberOfSubstrings(string s) {
        return helper(s,3) - helper(s,2);
    }
};
