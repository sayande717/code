public class MajorityElement {
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
        int[] arr = {1,1,3,3,3,3,3,3,4,4};
        int element = findElement(arr);
        System.out.println((element==-1)?"Element not found.":element);
    }
}