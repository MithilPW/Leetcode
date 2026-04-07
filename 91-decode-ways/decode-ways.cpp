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
    int solveREusingTabulation(string &s){
        //i will reach the end of the string
        vector <int> dp(s.size() + 1,0);
        dp[s.size()] = 1;

        for(int i = s.size()-1;i>=0;i--){

        int ways = dp[i+1];

        if(i + 1 < s.size()){
            int n = (s[i] - '0') * 10 + (s[i+1] - '0');
            if(n >= 10 && n <= 26){
                ways += dp[i+2];
                
            }
        }
            dp[i] = s[i] == '0' ? 0 : ways;
        }
        return dp[0];

    }
    int solveREusingSO(string &s){
        //i will reach the end of the string
        vector <int> dp(s.size() + 1,0);

        int curr = 0;
        int next1 = 1;
        int next2 = 0;

        for(int i = s.size()-1;i>=0;i--){

        int ways = next1;

        if(i + 1 < s.size()){
            int n = (s[i] - '0') * 10 + (s[i+1] - '0');
            if(n >= 10 && n <= 26){
                ways += next2;
                
            }
        }
            curr = s[i] == '0' ? 0 : ways;

            //shifting
            next2 = next1;
            next1 = curr;
        }
        return next1;

    }
    int numDecodings(string s) {


        return solveREusingSO(s);
    }
};