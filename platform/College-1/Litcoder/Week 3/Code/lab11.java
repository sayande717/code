import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

public class Main {

    private void printCommon() {
        Scanner in = new Scanner(System.in);
        HashMap<String, Integer> freq = new HashMap<String, Integer>();

        // Loop to read input 3 times
        for (int iter = 0; iter < 3; iter++) {
            String[] arr = in.nextLine().split(" ");
            for (String num : arr) {
                freq.put(num, freq.getOrDefault(num, 0) + 1);
            }
        }

        boolean found = false;

        // Iterate through the HashMap to find common elements
        for (Map.Entry<String, Integer> entry : freq.entrySet()) {
            if (entry.getValue() == 3) {
                found = true;
                System.out.printf("%s ", entry.getKey());
            }
        }

        if (!found) {
            System.out.print("No Elements");
        }

        in.close();
    }

    public static void main(String[] args) {
        Main ob = new Main();
        ob.printCommon();
    }
}
