public class temp {
    private static String swap2Nibbles(String num) {
        String first = num.substring(0,4);
        String second = num.substring(4,num.length());
        System.out.println(first+" "+second);
        return new String(second + first);
    }
    public static void main(String[] args) {
        System.out.println(swap2Nibbles(args[0]));
        System.exit(0);
    }
}