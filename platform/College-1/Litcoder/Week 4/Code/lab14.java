/* The changes we can make are: `RX` -> `XR`, and `XL` -> `LX`.
 * First of all, check the length of both the strings. If they aren't equal, there's no point in checking further, so print false.
 * Next, if we remove all X's from the strings,
 * a. The number of R's and L's in them will be equal.
 * b. The relative order of the R's & L's will be maintained (stable order).
 * Example:
 * String 1: RXXLRXRXL -> (Remove X's) -> RLRRL
 * String 2: XRLXXRRLX -> (Remove X's) -> RLRRL
 * If the resultant strings match, print true, else print false.
 */

import java.util.Scanner;

public class Main {
    private String removeX(String str) {
        String outStr = new String("");
        for (int index = 0; index < str.length(); index++) {
            char current = str.charAt(index);
            if (current != 'X') {
                outStr += current;
            }
        }
        return outStr;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Main ob = new Main();
        String in1 = in.nextLine();
        String in2 = in.nextLine();

        // ERROR: String lengths are not same.
        if (in1.length() != in2.length()) {
            System.out.print("false");
            System.exit(0);
        }

        in1 = ob.removeX(in1);
        in2 = ob.removeX(in2);

        for (int index = 0; index < in1.length(); index++) {
            if (in1.charAt(index) != in2.charAt(index)) {
                System.out.print("false");
                System.exit(0);
            }
        }
        
        System.out.print("true");
        in.close();
    }
}
