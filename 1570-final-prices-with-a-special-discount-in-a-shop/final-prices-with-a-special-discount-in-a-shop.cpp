class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
    stack<int> st;
    vector<int> ans(prices.size());


    for(int i=prices.size()-1;i>=0;i--){
        int curr = prices[i];

        while(!st.empty() && st.top() > curr){
            st.pop();
        }
        if(st.empty()){
            ans[i] = curr;
        }
        else{
            ans[i] = curr-st.top();
        }
        st.push(curr);
    }
    return ans;
    }
};