public class LeaderInArray {
    private static void printLeaders2Loops(int[] arr) {
        int n = arr.length;
        // Input array is empty
        if(n==0) {
           return;
        }

        // The only element is always a Leader.
        if(n==1) {
            System.out.print(arr[0]+" ");
        }

        // The last element can't be compared with itself.
        for(int i=0;i<(n-1);i++) {
            int j;
            for(j=(i+1);j<(n-1);j++) {
                if(arr[j]>arr[i]) {
                    break;
                }
            }
            if(j==(n-1)) {
                // arr[i] is a leader.
                System.out.print(arr[i]+" ");
            }
        }

        // The last element is printed as-is, since it's automatically a Leader.
        System.out.print(arr[n-1]);
    }
    // Prints the Leaders from the end of the array.
    private static void printLeaders1Loop(int[] arr) {
        int n = arr.length;
        // Input array is empty
        if(n==0) {
            return;
        }

        // leaders[len-1] = true;
        System.out.print(arr[n-1]+" ");

        int leader=arr[n-1];
        for(int i=(n-2);i>=0;i--) {
            if(arr[i] > leader) {
                // arr[i] is a Leader.
                System.out.print(arr[i]+" ");
                leader = arr[i];
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {5,6,7,0,1,3,2};

        System.out.print("Leaders (2 Loops): ");
        printLeaders2Loops(arr);

        System.out.println();

        System.out.print("Leaders (1 Loop): ");
        printLeaders1Loop(arr);

        System.exit(0);
    }
}
