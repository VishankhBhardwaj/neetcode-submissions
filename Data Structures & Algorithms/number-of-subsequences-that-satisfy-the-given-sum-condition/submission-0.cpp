class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int MOD = 1e9+7;
        int res = 0;
        int l = 0;
        int r = n-1;
        vector<int>power(n,1);
        for(int i=1;i<n;i++){
            power[i] = (power[i-1]*2)%MOD;
        }
        while(l<=r){
            if(nums[l] + nums[r]<=target){
                res = (res+power[r-l])%MOD;
                l++;
            }else r--;
        }
        return res;
    }
};