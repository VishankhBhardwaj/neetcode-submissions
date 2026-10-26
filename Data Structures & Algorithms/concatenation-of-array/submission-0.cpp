class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(2*n,0);
        for(int i=0;i<2*n;i++){
            int idx = i%n;
            ans[i] = nums[idx];
        }
        return ans;
    }
};