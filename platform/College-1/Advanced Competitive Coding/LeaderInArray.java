public class LeaderInArray {
    private static boolean[] findLeaders(int[] arr) {
        int len = arr.length;
        // Input array is empty
        if(len==0) {
            return new boolean[] {};
        }

        boolean[] leaders = new boolean[len];
        // Input array only contains 1 element.
        if (len==1) {
            leaders[0] = true;
            return leaders;
        }
        leaders[len-1] = true;

        for(int i=0;i<len-1;i++) {
            int j;
            for(j=i+1;j<len-1;j++) {
                if(arr[j]>arr[i]) {
                    break;
                }
            }
            if(j==len-1) {
                leaders[i] = true;
            }
        }
        return leaders;
    }
    public static void main(String[] args) {
        int[] arr = {5,6,7,0,1,3,2};
        boolean[] result = findLeaders(arr);
        System.out.print("Leaders: ");
        for(int i=0;i<arr.length;i++) {
            if(result[i]==true) {
                System.out.print(arr[i]+" ");
            }
        }
        System.exit(0);
    }
}
