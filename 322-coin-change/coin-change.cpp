class Solution {
public:
    int solveUsingRec(vector<int>& coins,int amount){

        // base case

        if(amount == 0){
            return 0;
        }

        //iss amount ko create karne k liye
        // i will try each and every couin

        int mini = INT_MAX;
        for(int i = 0;i < coins.size();i++){
            if(coins[i] <= amount){
                //valid case
                //maine ek coin use krlia

                int recursionKaAns = solveUsingRec(coins,amount-coins[i]);
                //recursion ka answer can be valid or invalid

                if(recursionKaAns != INT_MAX){
                    //ek valid answer mila h
                    // it may or may not be a minimum answer

                    mini = min(mini , 1 + recursionKaAns);
                }
            }
        }
        return mini;
    }
    int solveUsingMemo(vector<int>& coins,int amount,vector <int> &dp){

        // base case

        if(amount == 0){
            return 0;
        }

        //iss amount ko create karne k liye
        // i will try each and every couin
        if(dp[amount] != -1){
            return dp[amount];
        }
        int mini = INT_MAX;

        
        for(int i = 0;i < coins.size();i++){
            if(coins[i] <= amount){
                //valid case
                //maine ek coin use krlia

                int recursionKaAns = solveUsingMemo(coins,amount-coins[i],dp);
                //recursion ka answer can be valid or invalid

                if(recursionKaAns != INT_MAX){
                    //ek valid answer mila h
                    // it may or may not be a minimum answer

                    mini = min(mini , 1 + recursionKaAns);
                    
                }
            }
        }
        dp[amount] = mini;
        return mini;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = amount;
        vector<int> dp(n+1,-1);
        int ans = solveUsingMemo(coins,amount,dp);
        if(ans == INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};