public class SegmentedSieve {
    static void SegSieve(int l, int h) {
        // Step 1
        boolean[] nonPrime = new boolean[h - l + 1];

        // condition is same as p<=sqrt(h)
        for (int p = 2; p * p <= h; p++) {
            int sm = (l / p) * p;
            if (sm < l) {
                sm = sm + p;
            }

            // Adjust index: i-l
            // - When i=10, i-l = 10-10=0
            // - When i=11, i-1 = 11-10=1
            for (int i = sm; i <= h; i += p) {
                nonPrime[i-l] = true;
            }
        }
        
        // Adjust index: i-l
        for (int i = l; i <= h; i++) {
            if (!nonPrime[i-l]) {
                System.out.print(i + " ");
            }
        }
    }

    public static void main(String[] args) {
        SegSieve(10, 30);
    }
}