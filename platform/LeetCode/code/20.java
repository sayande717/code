// 27. https://leetcode.com/problems/remove-element/

class Solution {
    public int removeElement(int[] nums, int val) {
        int start = 0, end = 0;
        int j=0;
        for(int i=0;i<nums.length;i++) {
            if(nums[i] != val) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j++;
            }
        }
        return j;
    }
}