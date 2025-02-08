import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int target = in.nextInt();
        in.nextLine(); // Consume the newline character
        
        String[] num = in.nextLine().split(" ");
        int size = num.length;
        int count = 0;

        // Possible: NumberFormatException
        try {
            for (int ptr1 = 0; ptr1 < size; ptr1++) {
                int num1 = Integer.parseInt(num[ptr1]);
                for (int ptr2 = ptr1 + 1; ptr2 < size; ptr2++) {
                    int num2 = Integer.parseInt(num[ptr2]);
                    if ((num1 + num2) % target == 0) {
                        count++;
                    }
                }
            }
        } catch (Exception e) {
            System.exit(1); // Exit the program if an exception is caught
        }

        System.out.print(count);
        in.close();
    }
}
