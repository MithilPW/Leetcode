class Solution {
public:
    int solve(int n , vector<int> &dp){
        if(n<=1){
            return n;
        }

        if(dp[n] != -1){
            return dp[n];
        }
        int ans = solve(n-1,dp) + solve(n-2,dp);
        dp[n] = ans;
        return dp[n];
    }
    int fib(int n) {
        vector <int> dp(n+100,-1);
        int ans = solve(n,dp);
        return ans;
    }
};