class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max = (nums.size())/2;
        int ans = 0;
        if(nums.size() == 1){
            ans = nums[0];
            return ans;
        }
        for(int i = 0;i<nums.size();i++){
            int count = 0;
            for(int j=i+1;j<nums.size();j++){

                if(nums[i] == nums[j]){
                    count++;
                }
                if(count+1 > max){
                ans = nums[i];
                break;
                }    
            }
            if(count+1 > max){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};