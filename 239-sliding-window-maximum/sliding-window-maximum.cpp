class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; 
        vector<int> ans;

        //first window ko process karo

        for(int i=0;i<k;i++){
            int element = nums[i];

            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        for(int i=k;i<nums.size();i++){
            ans.push_back(nums[dq.front()]);

            if(!dq.empty() && i - dq.front() >= k){
                dq.pop_front();
            }
            int element = nums[i];
            while(!dq.empty() && element > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        return ans;


        // int n = nums.size();

        // for(int index = 0; index < n; index++) {

        //     if(!dq.empty() && dq.front() <= index - k) {
        //         dq.pop_front();
        //     }

        //     while(!dq.empty() && nums[dq.back()] <= nums[index]) {
        //         dq.pop_back();
        //     }

        //     dq.push_back(index);


        //     if(index >= k - 1) {
        //         result.push_back(nums[dq.front()]);
        //     }
        // }

        // return result;
    }
};
