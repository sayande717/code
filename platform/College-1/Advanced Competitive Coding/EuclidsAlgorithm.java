public class EuclidsAlgorithm {
    private static int gcd(int a, int b) {
        if(b==0) {
            return a;
        }
        
        return gcd(b, a%b);
    }
    public static void main(String[] args) {
        // a,b = args[0],args[1]
        int a = Integer.parseInt(args[0]);
        int b = Integer.parseInt(args[1]);
        System.out.print("GCD: ");
        // GCD of 0,1,2,3 is 0,1,2,3
        if(a>=0&&a<=3) {
            System.out.print(a);
            System.exit(0);
        } else if (b>=0 && b<=3) {
            System.out.print(b);
            System.exit(0);
        } else {
            System.out.println(gcd(a,b));
            System.exit(0);
        }
    }
}