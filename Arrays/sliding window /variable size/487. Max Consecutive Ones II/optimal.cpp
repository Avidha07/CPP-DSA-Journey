public class Solution {

    public int findMaxConsecutiveOnes(int[] nums) {

        int n = nums.length;
        int i = 0, j = 0;
        int cnt = 0;
        int maxLen = 0;

        while (j < n) {

            if (nums[j] == 0) {
                cnt++;
            }

            while (cnt > 1) {
                if (nums[i] == 0) {
                    cnt--;
                }
                i++;
            }

            maxLen = Math.max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
}
