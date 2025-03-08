// Find the missing number in a given array.
// Numbers are in the range (1-n).
public class findMissingNumberInArray {
    private static int findMissing(int n, int[] arr) {
        int totalSum = n*(n+1)/2;
        int arraySum = 0;
        for(int i=0;i<(n-1);i++) {
            arraySum+=arr[i];
        }
        return (totalSum-arraySum);
    }
    public static void main(String[] args) {
        // INPUT hardcoded
        // @param n = number of elements, including missing element.
        // @param arr = Array, with the element missing.
        int n = 10;
        int[] arr = {6,1,2,8,3,4,7,10,5};
        System.out.print("Missing number: "+findMissing(n,arr));
        System.exit(0);
    }
}