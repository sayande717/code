// 14. https://leetcode.com/problems/longest-common-prefix/
import java.util.Arrays;

class Solution {
    public String longestCommonPrefix(String[] strs) {
        Arrays.sort(strs);
        String string1 = strs[0];
        String string2 = strs[strs.length-1];
        int limit = 0;
        while(limit < string1.length() && limit < string2.length()) {
            if(string1.charAt(limit) == string2.charAt(limit)) {
                limit++;
            }
            else {
                break;
            }
        }
        return string1.substring(0,limit);
    }
}