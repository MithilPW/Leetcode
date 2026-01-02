class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int n = nums.size()/2;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i <= nums.size()-n ; i++){
            int count = 0;

            for(int j = i + 1;j<nums.size();j++){

                if(nums[i] == nums[j]){
                    count ++;
                }
                else{
                    break;
                }
            }
            if(count == n-1){
                return nums[i];
            }

        }
        return 0;
    }
};