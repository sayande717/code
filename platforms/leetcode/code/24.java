// 66. https://leetcode.com/problems/plus-one/

class Solution {
    public int[] plusOne(int[] digits) {
        for(int index = digits.length-1;index>=0;index--) {
            if(digits[index]<9) {
                digits[index]++;
                return digits;
            }
            // if digits[index] == 9
            digits[index] = 0;
        }
        // By default, all elements in a new array have a value of 0.
        digits = new int[digits.length+1];
        digits[0] = 1;
        return digits;
    }
}