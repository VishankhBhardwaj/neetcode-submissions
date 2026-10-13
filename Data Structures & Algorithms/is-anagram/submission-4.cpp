class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>hash(26,0);
        if(s.length()==t.length()){
            for(int i=0;i<s.length();i++){
                hash[s[i]-97]+=1;
            }
            for(int j=0;j<t.length();j++){
                hash[t[j]-97]-=1;
                if(hash[t[j]-97]<0){
                    return false;
                }
            }
            return true;
        }
        else{return false;}
    }
};
