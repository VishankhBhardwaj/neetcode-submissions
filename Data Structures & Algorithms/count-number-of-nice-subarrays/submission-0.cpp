class Solution {
public:
    int helper(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int n = nums.size();
        int i = 0;
        int oddCount = 0;
        int ans = 0;

        for (int j = 0; j < n; j++) {
            if (nums[j] % 2 != 0)
                oddCount++;

            while (oddCount > k) {
                if (nums[i] % 2 != 0)
                    oddCount--;
                i++;
            }

            ans += j - i + 1;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};