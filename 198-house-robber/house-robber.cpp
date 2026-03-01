class Solution {
public:
    int solveUsingRec(vector<int>& nums,int index){

        //base case
        if(index >= nums.size()){
            return 0;
        }
        int include = nums[index] + solveUsingRec(nums,index+2);
        int exclude = 0 + solveUsingRec(nums,index+1);
        int ans = max(include,exclude);
        return ans;
    }

    //1D DP
    //REC + Memoisation - top down
        int solveUsingMem(vector<int>& nums,int index,vector <int> &dp){

        //base case
        if(index >= nums.size()){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int include = nums[index] + solveUsingMem(nums,index+2,dp);
        int exclude = 0 + solveUsingMem(nums,index+1,dp);
        int ans = max(include,exclude);
        dp[index] = ans;
        return ans;
    }

    int rob(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        // int ans = solveUsingRec(nums,index);
        vector <int> dp(n+1,-1);
        int ans = solveUsingMem(nums,index,dp);
        return ans;
    }
};