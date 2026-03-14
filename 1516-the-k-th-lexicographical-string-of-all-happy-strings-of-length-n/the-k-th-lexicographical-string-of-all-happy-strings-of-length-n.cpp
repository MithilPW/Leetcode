class Solution {
public:
    string ans = "";
    int count = 0;

    void solve(int n, int k, string curr){
        if(curr.size() == n){
            count++;
            if(count == k){
                ans = curr;
            }
            return;
        }

        for(char ch : {'a','b','c'}){
            if(curr.empty() || curr.back() != ch){
                solve(n, k, curr + ch);
            }
        }
    }

    string getHappyString(int n, int k) {
        solve(n, k, "");
        return ans;
    }
};