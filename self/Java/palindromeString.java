class palindromeString {
    private static boolean isPalindrome(String inputStr) {
        int pointer1=0, pointer2=inputStr.length()-1;
        while(pointer1<pointer2) {
            if(inputStr.charAt(pointer1)!=inputStr.charAt(pointer2)) {
                return false;
            }
            pointer1++;
            pointer2--;
        }
        return true;
    }
    public static void main(String[] args) {
       System.out.println(isPalindrome("abcba"));
    }
}
