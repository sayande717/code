import java.util.HashMap;
public class StrobogramaticNumber {
    public static void main(String[] args) {
        HashMap<Character,Character> map = new HashMap<>();
        // Only 6 (with 9), 0, 1 & 8 can be strobogrammatic.
        // Examples: 609, 906, 1001 etc.
        map.put('1', '1');
        map.put('0', '0');
        map.put('6', '9');
        map.put('9', '6');
        map.put('8', '8');
        String input = args[0];
        for(int l=0,h=input.length()-1;l<=h;l++,h--) {
            // If map doesn't contain the character (integer), the number cannot be Strobogrammatic.
            if(!map.containsKey(input.charAt(l))) {
                System.out.println(input+" is not Strobogrammatic");
                System.exit(0);
            }

            if(map.get(input.charAt(l))!=input.charAt(h)) {
                System.out.println(input+" is not Strobogrammatic");
                System.exit(0);
            }
        }
        System.out.println(input+" is Strobogrammatic");
    }
}