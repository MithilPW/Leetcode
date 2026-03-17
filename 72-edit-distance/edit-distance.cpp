class Solution {
public:

    int solveUsingRecursion(string &a,string &b,int i,int j){
        if( i == a.length()){
            return b.length()-j;
        }

        if(j == b.length()){
            return a.length()-i;
        }

        int ans = 0;

        if(a[i] == b[j]){
            ans = solveUsingRecursion(a,b,i+1,j+1);
        }

        else{
            //operation perform karo

            int insert = 1 + solveUsingRecursion(a,b,i,j+1);
            int deleted = 1 + solveUsingRecursion(a,b,i+1,j);
            int replace = 1 + solveUsingRecursion(a,b,i+1,j+1);

            ans = min(insert,min(deleted,replace));
        }

        return ans;
    }
    int solveUsingMemo(string &a,string &b,int i,int j,vector <vector<int>> &dp){
        if( i == a.length()){
            return b.length()-j;
        }

        if(j == b.length()){
            return a.length()-i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int ans = 0;

        if(a[i] == b[j]){
            ans = solveUsingMemo(a,b,i+1,j+1,dp);
            dp[i][j] = ans;
        }

        else{
            //operation perform karo

            int insert = 1 + solveUsingMemo(a,b,i,j+1,dp);
            int deleted = 1 + solveUsingMemo(a,b,i+1,j,dp);
            int replace = 1 + solveUsingMemo(a,b,i+1,j+1,dp);

            ans = min(insert,min(deleted,replace));

            dp[i][j] = ans;
        }

        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        if(word1.length() == 0){
            return word2.length();
        }

        if(word2.length() == 0){
            return word1.length();
        }

        vector <vector <int>> dp (word1.length(),vector<int> (word2.length(),-1));

        int i = 0;
        int j = 0;
        
        return solveUsingMemo(word1,word2,i,j,dp);
    }
};