class Solution {
   public:
    int helper(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        unordered_map<int, int> mpp;
        int ans = 0;
        for (int j = 0; j < n; j++) {
            mpp[nums[j]]++;
            while (mpp.size() > k) {
                mpp[nums[i]]--;
                if (mpp[nums[i]] == 0) {
                    mpp.erase(nums[i]);
                }
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};