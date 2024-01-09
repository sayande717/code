// 34. https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] answer = {-1,-1};
        
        answer[0] = searchElement(nums, target, true);
        // There's no point in finding the ending position if the element is not present in the array.
        if(answer[0] != -1) {
            answer[1] = searchElement(nums, target, false);
        }
        
        return answer;
    }
    
    int searchElement(int[] nums, int target, boolean startIndex) {
        int start = 0;
        int end = nums.length-1;
        int potentialAnswer = -1;
        while(start<=end) {
            int mid = start+(end-start)/2;
            if(nums[mid] < target) {
                start = mid + 1;
            }
            else if(nums[mid] > target) {
                end = mid - 1;
            }

            // if middle element == target, that may be a potential answer.
            else {
                potentialAnswer = mid;
                if(startIndex) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
        }
        return potentialAnswer;
    }
}