// Swap the nibbles in a binary byte.
// - A nibble consists of 4 bits.
// - In a binary byte (8 bits) `01100100`, `0110` is the first nibble, `0100` is the 2nd one.
// - The task here is to swap the 2 nibbles in the binary byte. Example: `01101000` -> `01000110`
public class temp {
    private static String swap_nibbles(String input) {
        int len = input.length();
        int mid = len/2;
        return (input.substring(mid,len)+input.substring(0,mid));
    }
    public static void main(String[] args) {
        // Input: args[0]: 01100100 (String)
        System.out.println(swap_nibbles(args[0]));
        System.exit(0);
    }
}
