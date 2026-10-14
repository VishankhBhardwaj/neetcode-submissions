class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(j<n){
            int cnt = 1;
            while(j+1<n && nums[j] == nums[j+1]){
                j++;
                cnt++;
            }
            for(int k = 0;k<min(2,cnt);k++){
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};