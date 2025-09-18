class Solution {
public:
    int removeElementHelper(vector<int>& nums, int val, int i, int count) {
        if (i == nums.size()) return count;
        if (nums[i] != val) {
            nums[count] = nums[i];  
            return removeElementHelper(nums, val, i + 1, count + 1);
        }
        return removeElementHelper(nums, val, i + 1, count);
    }
    int removeElement(vector<int>& nums, int val) {
        return removeElementHelper(nums, val, 0, 0);
    }
};
