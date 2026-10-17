class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        int i = 0;
        int maxi = 0;
        for(int j=0;j<n;j++){
            if(nums[j] == 0) cnt++;
            while(i<=j && cnt >k){
                if(nums[i] == 0) cnt--;
                i++;
            }
            maxi = max(maxi,j-i+1);
        }
        return maxi;
    }
};