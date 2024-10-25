// 20. https://leetcode.com/problems/valid-parentheses/

import java.util.Stack;
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        for(int index = 0;index<s.length();index++) {
            char currentChar = s.charAt(index);
            if(currentChar == '(') {
                stack.push(')');
            }
            else if(currentChar == '[') {
                stack.push(']');
            }
            else if(currentChar == '{') {
                stack.push('}');
            }
            else if(stack.isEmpty() || stack.pop() != currentChar) {
                return false;
            }
            
        }
        return stack.isEmpty();
    }
}