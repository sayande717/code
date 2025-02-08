import java.util.Scanner;

public class ChineseRemainder {

    public static final int len = 3;
    
    private static void takeInput(int[] a, int[] m) {
        Scanner in = new Scanner(System.in);
        for(int i=0;i<len;i++) {
            System.out.print("Enter div (a_"+(i+1)+"): "); a[i] = in.nextInt();
            System.out.print("Enter mod (m_"+(i+1)+"): "); m[i] = in.nextInt();
        }
        in.close();
    }

    // Brute Force, Time: O(M), M is M_Prod=m_1*m_2*m_3...m_m
    private static int calcRemainderNE(int[] a, int[] m) {
        int i=1;
        while(true) {
            if(i%m[0]==a[0] && i%m[1]==a[1] && i%m[2]==a[2]) {
                break;
            } else {
                i++;
            }
        }
        return i;
    }
    
    // Direct Calculation, Time: O(n^2), n is the number of equations
    private static int calcRemainderE(int[] a, int[] m) {
        // Calculate: M, M_0 ... M_(len-1)
        int M_Prod = 1;
        int[] M = new int[len];
        int[] M_Inv = new int[len];
        int X=0;
        for(int i=0;i<len;i++) {
            M_Prod = M_Prod*m[i];
        }

        for(int i=0;i<len;i++) {
            M[i] = M_Prod/m[i];
        }

        // Calculate: M_Inv (M Inverse)
        for(int i=0;i<m[i];i++) {
            int j=1;
            while((M[i]*j)%m[i]!=1) {
                j++;
            }
            M_Inv[i] = j;
        }

        // Calculate: X
        for(int i=0;i<len;i++) {
            X = X + (a[i]*M[i]*M_Inv[i]);
        }
        X = X%M_Prod;
        return X;
    }
    public static void main(String[] args) {
        // Sample values: `div` or `a`={2,3,2} | `mod` or `m` = {3,5,7} | Chinese Remainder: 23
        int[] div = new int[len];
        int[] mod = new int[len];
        // WARN: Array lengths of div & mod must be same
        takeInput(div, mod);
        
        System.out.println("Chinese Remainder (Direct Calculation): "+calcRemainderE(div, mod));
        System.out.println("Chinese Remainder (Brute Force): "+calcRemainderNE(div, mod));
        
        System.exit(0);
    }
}
