public class KaratsubaMultiplication {
    private static int power(int base, int exponent) {
        return (int)(Math.pow(base, exponent));
    }

    private double calculate(int N1, int N2) {
        int n = (int)Math.max((int)(Math.log10(N1))+1,(int)(Math.log10(N2)+1));
        int n_half = (n/2);

        // Gather a,b,c,d
        int a = N1/power(10,n_half);
        int b = N1%power(10,n_half);
        int c = N2/power(10,n_half);
        int d = N2%power(10,n_half);

        // steps
        int s1 = (a*c);
        int s2 = (b*d);
        int s3 = (a+b)*(c+d);
        int s4 = s3-s2-s1;
        int s5 = s1*power(10, n) + s4*power(10, n_half) + s2;
        // Result
        return s5;
    }
    public static void main(String[] args) {
        KaratsubaMultiplication ob = new KaratsubaMultiplication();
        int num1 = 1234;
        int num2 = 5678;
        System.out.println("Result: "+ob.calculate(num1,num2));
        
        System.exit(0);
    }
}
