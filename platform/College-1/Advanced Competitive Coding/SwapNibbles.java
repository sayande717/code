// Swap the nibbles in a binary byte.
public class SwapNibbles {
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
