class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        long long sum = 0;
        long long maxi = 0;
        unordered_map<int, int> mpp;

        for (int j = 0; j < n; j++) {
            sum += nums[j];
            mpp[nums[j]]++;

            while (j - i + 1 > k) {
                sum -= nums[i];
                mpp[nums[i]]--;

                if (mpp[nums[i]] == 0)
                    mpp.erase(nums[i]);

                i++;
            }

            if (j - i + 1 == k && mpp.size() == k) {
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};