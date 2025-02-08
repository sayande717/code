import static java.lang.Math.sqrt;

class EulerPhi {
    private static int euler(int n){
        int result=n;
        for(int p=2;p<sqrt(n);p++) {
            // if n is perfectly divisible by p, keep dividing n by p until it can no longer be divided.
            // That is, remove all occurences of p in n.
            if(n%p==0) {
                while(n%p==0) {
                    n=n/p;
                }
                result -= (result/p); // As per the formula of Euler's Phi.
            }
        }

        // If n is STILL > 1, that means it's a prime number, and also greater than sqrt(n).
        if(n>1) {
            result -= (result/n);
        }
        return result;
    }
    public static void main(String[] args) {
        System.out.println("Phi: "+euler(Integer.parseInt(args[0])));
    }
}