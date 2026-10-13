class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,bool>map1;
        for(auto i:nums){
            if(map1[i]==true){
                return i;
            }
            else{
            map1[i]=true;
            }
        }
    }
};
