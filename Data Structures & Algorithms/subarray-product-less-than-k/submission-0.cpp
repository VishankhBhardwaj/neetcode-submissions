class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int pro = 1;
        int ans = 0;
        for(int j=0;j<n;j++){
            pro = pro * nums[j];
            while(i<=j && pro>=k){
                pro = pro/nums[i++];
            }
            ans+=j-i+1;
        }
        return ans;
    }
};