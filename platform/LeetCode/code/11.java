// 1. https://leetcode.com/problems/two-sum

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] outList = new int[2];
        for(int element = 0;element<nums.length;element++) {
            for(int index = 0;index<nums.length;index++) {
                if(index == element) {
                    continue;
                }
                if(nums[element]+nums[index] == target) {
                    outList[0] = element;
                    outList[1] = index;
                    return outList;
                }
            }
        }
        return outList;
    }
}