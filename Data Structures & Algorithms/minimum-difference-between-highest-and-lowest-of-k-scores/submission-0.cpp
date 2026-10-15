class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i = 0;
        int mini = INT_MAX;
        for(int j=0;j<n;j++){
            while(i<j && j-i+1>k) i++;
            if(j-i+1 == k){
                mini = min(mini,abs(nums[i] - nums[j]));
            }
        }
        return mini;
    }
};