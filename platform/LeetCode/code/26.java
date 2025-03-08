// 344. https://leetcode.com/problems/reverse-string/
class Solution {
    public void reverseString(char[] s) {
        int first,last;
        for(first=0,last=s.length-1;first<last;first++,last--) {
            char temp = s[first];
            s[first] = s[last];
            s[last] = temp;
        }
    }
}