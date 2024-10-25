import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    private static final int MAX_STOCKS = 5;
    private static int validCombinations;

    private int findMin(int[] arr) {
        int min = arr[0];
        for (int index = 1; index < arr.length; index++) {
            if (arr[index] < min) {
                min = arr[index];
            }
        }
        return min;
    }

    public static void findSum(List<Integer> stocks, int budget, List<Integer> currentCombination, int currentIndex) {
        if (currentIndex == stocks.size()) {
            int totalPrice = 0;
            for (int i = 0; i < stocks.size(); i++) {
                totalPrice += currentCombination.get(i) * stocks.get(i);
            }
            if (totalPrice == budget) {
                for (int index = 0; index < stocks.size(); index++) {
                    System.out.print(currentCombination.get(index) + " ");
                }
                System.out.println();
                validCombinations++;
            }
            return;
        }

        for (int qty = 0; qty <= 5; qty++) {
            List<Integer> newCombination = new ArrayList<>(currentCombination);
            newCombination.add(qty);
            findSum(stocks, budget, newCombination, currentIndex + 1);
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        try {
            int target = in.nextInt();
            int iters = in.nextInt();
            in.nextLine(); // Swallow the next line.

            // ERROR: target is not positive
            if (target <= 0) {
                System.out.print("Invalid input");
                return;
            }

            ArrayList<Integer> prices = new ArrayList<>();
            for (int iter = 0; iter < iters; iter++) {
                String[] str = in.nextLine().split(" ");
                // Ignore str[0]
                // ERROR: Not an integer
                int price = Integer.parseInt(str[1]);
                if (price <= 0) {
                    System.out.print("The stock prices should be at least above 0");
                    return;
                } else if (price > target) {
                    System.out.print("One of the stock prices is higher than the target price");
                    return;
                }
                prices.add(price);
            }

            findSum(prices, target, new ArrayList<>(), 0);
            System.out.print(validCombinations);
        } catch (Exception e) {
            System.out.print("Invalid input");
        }
    }
}
