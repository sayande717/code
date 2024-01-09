// 1295. https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

class Solution {
    public int findNumbers(int[] nums) {
        int countnumbers = 0;
        for (int i = 0; i < nums.length; i++) {
            if(Integer.toString(nums[i]).length() %2 == 0)
                countnumbers++;
        }
        return countnumbers;
    }
}