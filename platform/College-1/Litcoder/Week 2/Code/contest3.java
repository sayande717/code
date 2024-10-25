import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static List<int[]> maxActivities(int[][] arr) {
        // Arrays.sort(arr, Comparator.comparingInt(a -> a[1]));
        List<int[]> selectedActivities = new ArrayList<>();
        selectedActivities.add(arr[0]);
        int lastFinishTime = arr[0][1];

        // Iterate through the remaining activities
        for (int i = 1; i < arr.length; i++) {
            if (arr[i][0] >= lastFinishTime) {
                selectedActivities.add(arr[i]);
                lastFinishTime = arr[i][1];
            }
        }
        return selectedActivities;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();

        int[] startTimes = new int[n];
        for (int i = 0; i < n; i++) {
            startTimes[i] = input.nextInt();
        }

        int[] finishTimes = new int[n];
        for (int i = 0; i < n; i++) {
            finishTimes[i] = input.nextInt();
        }

        int[][] activities = new int[n][2];
        for (int i = 0; i < n; i++) {
            activities[i][0] = startTimes[i];
            activities[i][1] = finishTimes[i];
        }

        List<int[]> result = maxActivities(activities);
        for (int[] activity : result) {
            System.out.println(activity[0] + " " + activity[1]);
        }

        input.close();
    }
}
