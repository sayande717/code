import java.util.Scanner;
import java.util.Arrays;

public class Main {

    private void insertionSort(String[] arr) {
        for (int iter = 1; iter < arr.length; iter++) {
            int jter = iter - 1;
            String target = arr[iter];
            while (jter >= 0 && arr[jter].compareTo(target) > 0) {
                arr[jter + 1] = arr[jter];
                jter -= 1;
            }
            arr[jter + 1] = target;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Main ob = new Main();

        int maxSweetness = Integer.parseInt(in.nextLine());
        String[] arr = in.nextLine().split(" ");
        in.close();

        ob.insertionSort(arr);

        // ERROR: Empty array
        if (arr.length == 0) {
            System.exit(0);
        }

        int count = 1;
        try {
            for (int index = 0; index < arr.length - 1; index++) {
                int candy1 = Integer.parseInt(arr[index]);
                int candy2 = Integer.parseInt(arr[index]) + 1;
                int sum = candy1 + (2 * candy2);
                count++;
                if (sum >= maxSweetness) {
                    break;
                }
            }
        } catch (Exception e) {
            System.exit(0);
        }

        System.out.print(count);
    }
}
