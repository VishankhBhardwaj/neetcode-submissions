class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int target = accumulate(nums.begin(),nums.end(),0) - x;
        if(target == 0) return n;
        int sum = 0;
        int cnt = 0;
        int i = 0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            while(i<j && sum>target){
                sum-=nums[i++];
            }
            if(sum == target){
                cnt = max(cnt,j-i+1);
            }
        }
        if(cnt == 0) return -1;
        return n - cnt;
    }
};
