import java.util.Scanner;
import java.util.Arrays;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        int maxFreq = 0;
        String[] input = in.nextLine().split(" ");
        Arrays.sort(input);

        for (String ID : input) {
            int currNum = Integer.parseInt(ID);
            freqMap.put(currNum, freqMap.getOrDefault(currNum, 0) + 1);
            int currFreq = freqMap.get(currNum);
            if (currFreq > maxFreq) {
                maxFreq = currFreq;
            }
        }

        for (String ID : input) {
            if (freqMap.get(Integer.parseInt(ID)) == maxFreq) {
                System.out.print(ID);
                System.exit(0);
            }
        }

        in.close();
    }
}
