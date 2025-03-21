public class MajorityElement {
    private static void sortArr(int[] arr) {
        int n = arr.length;
        boolean isSwapped = false;
        for(int i=(n-1);i>=0;i--) {
            for(int j=0;j<i;j++) {
                if(arr[j]>arr[j+1]) {
                    isSwapped = true;
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            if(!isSwapped) {
                break;
            } else {
                isSwapped = false;
            }
        }
    }
    private static int findElement(int[] arr) {
        int n = arr.length;
        for(int i=0;i<n;i++) {
            int count = 1;
            for(int j=(i+1);j<n;j++) {
                if(arr[i]==arr[j]) {
                    count++;
                } else {
                    break;
                }

            }
            if(count>(n/2)) {
                return arr[i];
            }
        }
        return -1;
    }
    public static void main(String[] args) {
        // Array NEEDS to be sorted for this algorithm to work.
        int[] arr = {1,3,1,3,4,3,4,3,3,3};
        sortArr(arr);
        int element = findElement(arr);
        System.out.println((element==-1)?"Element not found.":element);
    }
}