class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; 
        vector<int> result;
        int n = nums.size();

        for(int index = 0; index < n; index++) {

            if(!dq.empty() && dq.front() <= index - k) {
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] <= nums[index]) {
                dq.pop_back();
            }

            dq.push_back(index);


            if(index >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
