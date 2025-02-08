import java.util.Scanner;

public class Main {
    private boolean isPrime(int num) {
        if (num == 0 || num == 1) {
            return true;
        }
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Main ob = new Main();
        Scanner input = new Scanner(System.in);
        String str = input.next();
        int out = 0;
        int firstDigit = Character.getNumericValue(str.charAt(0));

        // Find the largest prime less than the first digit
        for (int iter = (firstDigit - 1); iter >= 1; iter--) {
            if (ob.isPrime(iter)) {
                out = out * 10 + iter;
                break;
            }
        }

        // Process the rest of the digits
        for (int count = 1; count < str.length(); count++) {
            for (int iter = 9; iter >= 1; iter--) {
                int temp = out * 10 + iter;
                if (ob.isPrime(temp)) {
                    out = temp;
                    break;
                }
            }
        }

        System.out.print(out);
    }
}
