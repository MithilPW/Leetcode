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
                
            }
        }
        return dp[i] = ways;
    }
int solveREusingTabulation(string &s, int i) {
    int n = s.size();
    vector<int> dp(n + 1, 0);

    dp[n] = 1; // base case

    for(int i = n - 1; i >= 0; i--) {

        if(s[i] == '0') {
            dp[i] = 0;
            continue;
        }

        int ways = dp[i + 1];  // take single digit

        if(i + 1 < n) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if(num >= 10 && num <= 26) {
                ways += dp[i + 2];  // take two digits
            }
        }

        dp[i] = ways;
    }

    return dp[0];
}
    int numDecodings(string s) {


        return solveREusingTabulation(s,0);
    }
};