class Solution {
public:

    bool solve(vector<int> &nums,int target,int i){

        if(target < 0 || i == nums.size()){
            return false;
        }
        
        if(target == 0){
            return true;
        }

        bool inc = solve(nums,target - nums[i],i+1);
        bool exc = solve(nums,target,i+1);

        return inc || exc;
    }
    bool solveusingMemo(vector<int> &nums,int target,int i,vector <vector<int>>&dp){

        if(target == 0){
            return true;
        }
        if(target < 0 || i == nums.size()){
            return false;
        }
        

        if(dp[i][target] != -1){
            return dp[i][target];
        }
        bool inc = solveusingMemo(nums,target - nums[i],i+1,dp);
        bool exc = solveusingMemo(nums,target,i+1,dp);

        dp[i][target] = inc || exc;
        return dp[i][target];
    }
    bool solveUsingTabulation(vector<int> &nums,int target){
        int n = nums.size();
        vector <vector<int>> dp(n+1,vector<int> (target+1, 0));

        for(int i = 0; i< nums.size() ;i++){
            dp[i][0] = 1;
        }

        for(int index = n-1 ; index>=0;index--){
            for (int t = 1 ; t <=target;t++){
                bool inc = 0;
                if(t - nums[index] >= 0){
                    inc = dp[index+1][t-nums[index]];
                }
                bool exc = dp[index+1][t];

                dp[index][t] = inc || exc;
            }
        }
        return dp[0][target];

    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 != 0 ){
            return false;
        }

        int target = sum / 2;

        int n = nums.size();

        return solveUsingTabulation(nums,target);
    }
};