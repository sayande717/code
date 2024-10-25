import java.util.Scanner;

public class Main {

    // Method to return error message
    private static String errorMessage() {
        return "Input is not in correct format or missing";
    }

    // Method to find the sum of elements in array between start and end indices
    private int findSum(String[] arr, int start, int end) {
        // Edge case: if start or end indices are out of bounds
        if (start < 0 || start >= arr.length || end < 0 || end >= arr.length) {
            return 0;
        }

        int sum = 0;
        try {
            for (int index = start; index <= end; index++) {
                sum = sum + Integer.parseInt(arr[index]);
            }
        } catch (Exception e) {
            System.out.print(errorMessage());
            System.exit(1);
        }

        return sum;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Main ob = new Main();

        try {
            // Read input and split into array
            String[] input = in.nextLine().split(" ");
            int len = input.length;

            // Check if input length is within the valid range
            if (len < 1 || len > Math.pow(10, 5)) {
                System.exit(1);
            }

            // Number of iterations
            int totalIter = in.nextInt();

            // Loop through each iteration to get start and end indices and calculate sum
            for (int iter = 1; iter <= totalIter; iter++) {
                int start = in.nextInt();
                int end = in.nextInt();
                System.out.println(ob.findSum(input, start, end));
            }
        } catch (Exception e) {
            System.out.print(errorMessage());
        }

        in.close();
    }
}
