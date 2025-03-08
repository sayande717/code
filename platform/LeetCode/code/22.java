// 58. https://leetcode.com/problems/length-of-last-word/

class Solution {
    public int lengthOfLastWord(String s) {
        int length = 0;
        boolean wordFound = false;
        for(int index = s.length()-1;index>=0;index--) {
            if(s.charAt(index) == ' ') {
                if(wordFound) {
                    break;
                }
            }
            else {
                length++;
                wordFound = true;
            }
        }
        return length;
    }
}