import java.util.Arrays;

public class temp {
    private static int[] swap(int[] arr) {
        int n = arr.length;
        int backup = arr[n-1];
        for(int i=(n-1);i>0;i--) {
            arr[i] = arr[i-1];
        }
        arr[0] = backup;
        return arr;
    }
    public static void main(String[] args) {
        int[] arr = {1,2,3,4,5};
        System.out.println(Arrays.toString(swap(arr)));
        System.exit(0);
    }
}