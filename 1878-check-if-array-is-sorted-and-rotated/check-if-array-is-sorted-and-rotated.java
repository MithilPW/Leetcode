class Solution {
    public boolean check(int[] nums) {
        int n = nums.length;
        int dropIndex = -1;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                dropIndex = i;
                break;
            }
        }

        if (dropIndex == -1) {
            return true;
        }

        int[] rotated = new int[n];
        int k = 0;

        for (int i = dropIndex + 1; i < n; i++) {
            rotated[k++] = nums[i];
        }

        for (int i = 0; i <= dropIndex; i++) {
            rotated[k++] = nums[i];
        }

        for (int i = 0; i < n - 1; i++) {
            if (rotated[i] > rotated[i + 1]) {
                return false;
            }
        }

        return true;
    }
}