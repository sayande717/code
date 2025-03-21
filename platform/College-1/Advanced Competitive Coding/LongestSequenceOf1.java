import java.util.Scanner;

public class LongestSequenceOf1 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Enter a binary number: "); String input = in.next();

        int max = 0;
        int current = 0;
        int previous = 0;

        for (int i = 0; i < input.length(); i++) {
            char chr = input.charAt(i);
            if (chr == '1') {
                current++;
                if (current == input.length()) {
                    max = current;
                    System.out.println(max);
                    System.exit(0);
                }
            } else {
                max = Math.max(max, current + previous + 1);
                previous = current;
                current = 0;
            }
        }

        max = Math.max(max, current + previous + 1);
        System.out.println(max);

        in.close();
        System.exit(0);
    }
}