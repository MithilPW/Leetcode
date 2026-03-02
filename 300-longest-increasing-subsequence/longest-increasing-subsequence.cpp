class Solution {
public:
    int solve(vector<int> &nums,int curr,int prev){

        //base case

        if(curr >= nums.size()){
            return 0;
        }
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solve(nums,curr+1,curr);
        }
        int exclude = 0 + solve(nums,curr+1,prev);

        int length = max(include,exclude);

        return length;
    }
    //2D DP
    //top down apporach
    int solveusingMemo(vector<int> &nums,int curr,int prev,vector<vector<int>>&dp){

        //base case

        if(curr >= nums.size()){
            return 0;
        }

        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1];
        }
        int include = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solveusingMemo(nums,curr+1,curr,dp);
        }
        int exclude = 0 + solveusingMemo(nums,curr+1,prev,dp);

        int length = max(include,exclude);
        dp[curr][prev+1] = length;
        return length;
    }

    int solveusingTabulation(vector<int>& arr){
        //create dp array
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        //base case and fill dp array

        for(int curr = n-1;curr>=0;curr--){
            for(int prev = curr-1;prev>=-1;prev--){
                int include = 0;
                if(prev == -1 || arr[curr] > arr[prev]){
                    include = 1 + dp[curr+1][curr+1];
                }
                int exclude = 0 + dp[curr+1][prev+1];

                dp[curr][prev+1] = max(include,exclude);
            }
            
        }
        return dp[0][0];
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev = -1;
        int curr = 0;

        // int n =nums.size();

        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = solveusingTabulation(nums);

        return ans;
    }
};