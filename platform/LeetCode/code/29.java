// 202. https://leetcode.com/problems/happy-number/

class Solution {
    protected int square(int input) {
        int output = 0;
        while(input != 0) {
            int remainder = input % 10;
            output = output + (remainder * remainder);
            input = input / 10;
        }
        return output;
    }

    public boolean isHappy(int n) {
        int current = n;
        int next = n;
        do {
            current = square(current);
            next = square(square(next));
        } while(current != next);
        return (current == 1);
    }
}