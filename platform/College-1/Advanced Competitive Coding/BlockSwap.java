import java.util.Scanner;

public class BlockSwap {
    private static void rotateOnceLeft(int[] arr) {
        int firstElement = arr[0];
        int n = arr.length;
        for(int i=1;i<n;i++) {
            arr[i-1] = arr[i];
        }
        arr[n-1]=firstElement;
    }

    // k decides the direction of rotation.
    private static void rotate(int[] arr, int k) {
        for(int i=0;i<k;i++) {
            rotateOnceLeft(arr);
        }
    }

    private static void printArr(int[] arr) {
        for(int i=0;i<arr.length;i++) {
            System.out.print(arr[i]+" ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] arr = {1,2,3,4,5,6,7,8,9,10};
        int n = arr.length;
        
        System.out.print("Original Array: ");
        printArr(arr);
        
        System.out.print("Enter `1` for Left Rotation, `2` for Right Rotation: ");
        int choice = in.nextInt();
        System.out.print("Enter the number of rotations: ");
        int k = in.nextInt();
        k = (k%n); // Every `n` steps, we don't have to rotate the array.
        switch(choice) {
            case 1:
                rotate(arr,k);
                break;
            case 2:
                k = (n-k);
                rotate(arr,k);
                break;
            default:
                System.exit(0);
        }

        System.out.print("Modified Array: ");printArr(arr);
        in.close();        
        System.exit(0);
    }
}
