class Solution {
public:
    int helper(vector<int>&nums,int k){
        int n = nums.size();
        int i =0; 
        int sum = 0;
        int ans = 0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            while(i<=j && sum>k){
                sum-=nums[i++];
            }
            ans+=j-i+1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal) - helper(nums,goal-1);
    }
};