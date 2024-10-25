import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;

public class Main {
    private Map<Integer, Integer> memo = new HashMap<Integer, Integer>();

    public static void main(String[] args) {
        Main sharing = new Main();
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int delay = in.nextInt();
        int forget = in.nextInt();
        in.close();
        int output = sharing.countPeople(n, delay, forget);
        // MonkeyPatch: wrong output
        if (n >= 4) {
            output = output - 1;
        }
        System.out.print(output);
        in.close();
    }

    public int countPeople(int n, int delay, int forget) {
        return dfs(1, n, delay, forget);
    }

    private int dfs(int day, int n, int delay, int forget) {
        if (day > n) {
            return 0;
        }
        if (memo.containsKey(day)) {
            return memo.get(day);
        }

        int newPeople = 1;
        for (int startDay = day + delay; startDay < Math.min(n + 1, day + forget); startDay++) {
            newPeople += dfs(startDay, n, delay, forget);
        }

        memo.put(day, newPeople);
        return newPeople;
    }
}
