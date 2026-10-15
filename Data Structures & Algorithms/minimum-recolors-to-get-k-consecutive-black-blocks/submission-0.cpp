class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int mini = INT_MAX;
        int cnt = 0;
        int i = 0;
        for(int j=0;j<n;j++){
            if(blocks[j] == 'W') cnt++;
            while(i<j && j-i+1>k){
                if(blocks[i] == 'W') cnt--;
                i++;
            }
            if(j-i+1 == k){
                mini = min(cnt,mini);
            }
        }
        return mini;
    }
};