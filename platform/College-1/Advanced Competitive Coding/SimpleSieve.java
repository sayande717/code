import java.util.ArrayList;

public class SimpleSieve {
    private static ArrayList<Integer> simpleSieve(int limit) {
        ArrayList<Integer> result = new ArrayList<Integer>();
        // integer 'limit' is included in the array.
        boolean[] isPrime = new boolean[limit+1];

        // By default, all values in the isPrime array (including 0 & 1) are false.
        for(int i=2;i<=limit;i++) {
            isPrime[i] = true;
        }

        for(int p=2;p*p<=limit;p++) {
            if(isPrime[p]) {
                for(int i=p*p;i<=limit;i+=p) {
                    isPrime[i]=false;
                }
            }
        }

        for(int p=2;p<=limit;p++) {
            if(isPrime[p]) {
                result.add(p);
            }
        }
        return result;
    }
    public static void main(String[] args) {
        System.out.println((simpleSieve(Integer.parseInt(args[0]))));
    }
}
