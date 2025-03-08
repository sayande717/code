import java.util.Arrays;

public class sortZeroAndOnes {
    private static int[] sort(int[] arr, int n) {
        for(int i=0,j=(n-1);i<=j;i++,j--) {
            if(arr[i]>arr[j]) {
                arr[i] = arr[i]+arr[j];
                arr[j] = arr[i]-arr[j];
                arr[i] = arr[i]-arr[j];
            }
        }
        return arr;
    }
    public static void main(String[] args) {
        int[] arr = {1,0,1,0,1,0,1,0,1,0};
        int n = arr.length;
        System.out.println(Arrays.toString(sort(arr,n)));
        System.exit(0);
    }
}
