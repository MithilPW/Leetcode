class Solution {
public:
    int solveRE(string &s,int i){
        //i will reach the end of the string

        if(i == s.size()){
            return 1;
        }

        if(s[i] == '0'){
            return 0;
        }

        int ways = solveRE(s,i+1);

        if(i + 1 < s.size()){
            int n = (s[i] - '0') * 10 + (s[i+1] - '0');
            if(n >= 10 && n <= 26){
                ways += solveRE(s,i+2);
            }
        }
        return ways;
    }
    int solveREusingMemoization(string &s,int i,vector<int>&dp){
        //i will reach the end of the string

        if(i == s.size()){
            return 1;
        }

        if(s[i] == '0'){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int ways = solveREusingMemoization(s,i+1,dp);

        if(i + 1 < s.size()){
            int n = (s[i] - '0') * 10 + (s[i+1] - '0');
            if(n >= 10 && n <= 26){
                ways += solveREusingMemoization(s,i+2,dp);
                dp[i] = ways;
            }
        }
        return ways;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return solveREusingMemoization(s,0,dp);
    }
};