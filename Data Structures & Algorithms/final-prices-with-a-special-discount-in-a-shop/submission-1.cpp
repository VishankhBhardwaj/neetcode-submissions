class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            int price = prices[i];
            while(!st.empty() && st.top()>price)st.pop();
            if(!st.empty()){
                prices[i] = prices[i] - st.top();
            }
            st.push(price);
        }
        return prices;
    }
};
