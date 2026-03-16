class Solution {
public:
    int solveUsingRecursion(int start, int end){
        if(start >= end){
            return 0;
        }

        int ans = INT_MAX;

        for(int i = start;i<=end;i++){
            ans = min(ans,i+max(solveUsingRecursion(start,i-1),solveUsingRecursion(i+1,end)));
        }
        return ans;
    }
    int solveUsingMemo(int start, int end,vector <vector<int>>&dp){
        if(start >= end){
            return 0;
        }

        int ans = INT_MAX;

        if(dp[start][end] != -1){
            return dp[start][end];
        }

        for(int i = start;i<=end;i++){
            ans = min(ans,i+max(solveUsingMemo(start,i-1,dp),solveUsingMemo(i+1,end,dp)));
            dp[start][end] = ans;
        }
        return dp[start][end];
    }
    int getMoneyAmount(int n) {

        vector < vector<int> >dp(n+1, vector<int>(n+1,-1));
        int ans = solveUsingMemo(1,n,dp);
        return ans;
    }
};
