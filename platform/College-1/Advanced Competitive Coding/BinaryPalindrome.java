public class BinaryPalindrome {
    private static boolean isPalindrome(String num) {
        for(int i=0,j=num.length()-1;i<j;i++,j--) {
            if(num.charAt(i)!=num.charAt(j)) {
                return false;
            }
        }
        return true;
    }

    // This generates the binary equivalent in reverse order, but shouldn't matter for our use case.
    private static String toBinary(int num) {
        String binary = new String("");
        while(num!=0) {
            int bit = num%2;
            binary = bit+binary;
            num = num/2;
        }
        return binary;
    }
    public static void main(String[] args) {
        try {
            String input = toBinary(Integer.parseInt(args[0]));    
            System.out.println("Binary Equivalent (in reverse): "+input);
            System.out.println("Check: "+isPalindrome(input));
        } catch (Exception e) {
            System.out.println("ERROR: Enter an integer.");
            System.exit(1);
        }
    }
}
