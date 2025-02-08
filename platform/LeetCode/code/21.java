// 26. https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution {
    public int strStr(String haystack, String needle) {
        for(int i = 0;i<haystack.length();i++) {
            if(haystack.charAt(i) == needle.charAt(0) && i+needle.length()-1 < haystack.length() && haystack.substring(i,i+needle.length()).equals(needle)) {
                return i;
            }
        }
        return -1;
    }
}