public class BoothsAlgorithm {
    private static int boothAlgorithm(int n1, int n2) {
        int m = n1;
        int q = n2;
        int A = n1;
        int S = -n1;
        int P = 0;
        int count = Integer.SiZE;

        System.out.print(count);
        while(count>0) {
            if((r&1)==1) { // Extracts the last binary digit
                P+=A;
                S=+M;
            }
            A<<=1;
            S<<=1;
            count--;
            r>>=1;
        }
        return P;
    }

    public static void main(String[] args) {
       // Take inputs in binary, or convert them to binary
       Scanner in = new Scanner(System.in);
       System.out.print("Enter in binary");
       int M = in.nextInt();
       int Q
    }
}
