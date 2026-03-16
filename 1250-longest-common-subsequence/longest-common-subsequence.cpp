class Solution {
public:
    int solveUsingRecursion(string text1,string text2,int i,int j){
        if(i == text1.length()){
            return 0;
        }

        if(j == text2.length()){
            return 0;
        }
        int ans = 0;
        if(text1[i] == text2[j]){
            ans =  1+solveUsingRecursion(text1,text2,i+1,j+1);
        }
        else{
            ans = 0 + max(solveUsingRecursion(text1,text2,i,j+1),solveUsingRecursion(text1,text2,i+1,j));
        }
        return ans;
    }
    int solveUsingMemo(string &text1,string &text2,int i,int j,vector<vector<int>>&dp){
        if(i == text1.length()){
            return 0;
        }

        if(j == text2.length()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;
        if(text1[i] == text2[j]){
            ans =  1+solveUsingMemo(text1,text2,i+1,j+1,dp);
        }
        else{
            ans = 0 + max(solveUsingMemo(text1,text2,i,j+1,dp),solveUsingMemo(text1,text2,i+1,j,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int solveUsingSO(string a,string b){
        vector<int> curr(b.length() + 1,0);
        vector<int> next(b.length() + 1,0);

        for(int i = a.length()-1;i>=0;i--){
            for(int j = b.length()-1;j>=0;j--){
                int ans = 0;
                if(a[i] == b[j]){
                    ans = 1 + next[j+1];
                }
                else{
                    ans = 0 + max(curr[j+1],next[j]);
                }

                curr[j] = ans;
            }

            //shift
            next = curr;
        }

        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // int i = 0;
        // int j = 0;
        // int n = text1.length();
        // int m = text2.length();
        // vector <vector<int>> dp(n+1 , vector<int>( m+1,-1));
        return solveUsingSO(text1,text2);
    }

};