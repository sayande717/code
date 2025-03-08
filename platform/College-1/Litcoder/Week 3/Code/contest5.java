import java.util.Scanner;

/*
 * Test Case:
 * 5
 * 1 0 0 0 0
 * 0 1 1 0 0
 * 0 1 1 0 0
 * 0 0 0 1 1
 * 0 0 0 1 1
 */

public class contest5 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int iters = in.nextInt();
        in.nextLine();

        int count = iters;

        for(int iter = 0; iter < iters; iter++) {
            String[] isConnected = in.nextLine().split(" ");
            for(int jter = iter+1; jter < iters; jter++) {
                if(isConnected[jter].equals("1")) {
                    count--;
                }
            }
        }

        System.out.print(count);
    }
}

