class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int M = nums.size();
        int N = M/3;
        if(M == 0){
            return ans;
        }
        int count = 1;
        for(int i = 1;i<=M;i++){
            
            if(i<M && nums[i] == nums[i-1]){
                count++;
            }
            else{
                if(count > N){
                ans.push_back(nums[i-1]);
                }
                count = 1;
            }

            
        }
        return ans;
    }
};