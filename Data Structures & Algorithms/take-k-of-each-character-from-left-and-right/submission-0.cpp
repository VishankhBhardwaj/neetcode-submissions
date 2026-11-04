class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int cnt = 0;
        int  i = 0;
        unordered_map<char,int>mpp;
        for(auto ch:s) mpp[ch]++;
        if(mpp['a']<k || mpp['b']<k || mpp['c']<k) return -1;
        for(int j=0;j<n;j++){
            mpp[s[j]]--;
            while(mpp[s[j]]<k){
                mpp[s[i]]++;
                i++;
            }
            cnt = max(cnt,j-i+1);
        }
        return n-cnt;
    }
};
