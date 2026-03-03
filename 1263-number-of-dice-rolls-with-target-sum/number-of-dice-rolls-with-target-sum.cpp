class Solution {
public:
    const int mod = 1e9 + 7;
    int solveusingRec(int n, int k, int target ,vector<vector<int>>&dp){
        
        if(n<0 || target < 0){
            return 0;
        }
        if(n == 0 && target == 0){
            return 1;
        }
        if(n == 0 && target != 0){
            return 0;
        }
        if(n != 0 && target == 0){
            return 0;
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        int ans = 0;
        for(int val=1;val <= k;val++){
            ans = (ans + solveusingRec(n-1,k,target-val,dp)) % mod;
            dp[n][target] = ans;
        }
        return ans;
    }
    int numRollsToTarget(int n, int k, int target) {

       int m = target;

       vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int ans = solveusingRec(n,k,target,dp);
       return ans;
    }
};