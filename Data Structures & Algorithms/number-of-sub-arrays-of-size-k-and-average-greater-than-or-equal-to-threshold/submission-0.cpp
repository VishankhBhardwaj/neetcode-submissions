class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int j = 0;
        int i = 0;
        int sum = 0;
        int avg = 0;
        int ans = 0;
        while(j<n){
            sum+=arr[j];
            while(i<j && j-i+1>k){
                sum-=arr[i];
                i++;
            }
            if(j-i+1 == k){
                avg = sum/(j-i+1);
                if(avg>=threshold) ans++;
            }
            j++;
        }
        return ans;
    }
};