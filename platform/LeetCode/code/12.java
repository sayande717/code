class Solution {
    public boolean isPalindrome(int x) {
        String input = Integer.toString(x);
        int head, tail;
        for(head = 0, tail = input.length()-1;head <= tail; head++,tail--) {
            if(input.charAt(head)!=input.charAt(tail)) {
                return false;
            }
        }
        return true;
    }
}
