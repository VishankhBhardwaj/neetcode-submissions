class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        vector<vector<int>> buckets(nums.size() + 1);
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto&[num,freq]:mpp){
            buckets[freq].push_back(num);
        }
        for(int i=buckets.size()-1;i>=0 && ans.size()<k;i--){
            for(auto num:buckets[i]){
                ans.push_back(num);
                if (ans.size() == k) break;
            }
        }
        return ans;
    }
};
