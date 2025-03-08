import java.util.Scanner;

public class Main {
    /* Input:
     * 5
     * 3
     * 2 4 3
     * 4 5 9
     * 3 3 11
     * We take the length of the array and number of queries as usual.
     * Next, we take the first query -> [2,4,3]. So, 3 will be added to all elements in range (2,4).
     * Instead of adding 3 to all 3 elements, we `mark` pos 2 by adding 3, and pos 4 by subtracting 3
     * So, the array: [0,3,0,-3,0]
     * Similarly, we continue processing other queries.
     * At the end, we traverse through the entire array and find the cumulative sum & max sum.
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the length of the array
        int len = sc.nextInt();
        int[] arr = new int[len];

        // Read the number of queries
        int iters = sc.nextInt();

        // Apply each query using the difference array technique
        for (int iter = 0; iter < iters; iter++) {
            int start = sc.nextInt();
            int end = sc.nextInt();
            int value = sc.nextInt();

            // Increment at the start of the range
            arr[start - 1] += value;

            // Decrement right after the end of the range, if within bounds
            if (end < len) {
                arr[end] -= value;
            }
        }

        // Find the maximum value after applying the operations
        int max = 0;
        int currentSum = 0;

        // Accumulate values and track the maximum sum
        for (int iter = 0; iter < len; iter++) {
            currentSum += arr[iter];
            if (currentSum > max) {
                max = currentSum;
            }
        }

        // Print the maximum value
        System.out.print(max);

        // Close the scanner
        sc.close();
    }
}
