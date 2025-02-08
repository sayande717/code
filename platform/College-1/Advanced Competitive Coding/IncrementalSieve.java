/**
 * The IncrementalSieve class provides a way to generate prime numbers incrementally.
 * It uses the Sieve of Eratosthenes algorithm to mark non-prime numbers.
 */
public class IncrementalSieve {
    private int currentMax;
    private boolean[] isPrime;

    /**
     * Constructs an IncrementalSieve with an initial size.
     * Initializes the sieve up to the given initial size.
     *
     * @param initialSize the initial size of the sieve
     */
    public IncrementalSieve(int initialSize) {
        currentMax = initialSize;
        isPrime = new boolean[currentMax + 1];
        for (int i = 2; i <= currentMax; i++) {
            isPrime[i] = true;
        }
        sieve(currentMax);
    }

    /**
     * Applies the Sieve of Eratosthenes algorithm up to the given limit.
     *
     * @param limit the upper limit for marking non-prime numbers
     */
    private void sieve(int limit) {
        for (int p = 2; p * p <= limit; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i <= limit; i += p) {
                    isPrime[i] = false;
                }
            }
        }
    }

    /**
     * Extends the sieve to a new limit if the new limit is greater than the current maximum.
     * Marks non-prime numbers in the extended range.
     *
     * @param newLimit the new upper limit for the sieve
     */
    public void extendSieve(int newLimit) {
        if (newLimit <= currentMax) {
            return;
        }
        boolean[] newIsPrime = new boolean[newLimit + 1];
        System.arraycopy(isPrime, 0, newIsPrime, 0, isPrime.length);
        for (int i = currentMax + 1; i <= newLimit; i++) {
            newIsPrime[i] = true;
        }
        isPrime = newIsPrime;
        sieve(newLimit);
        currentMax = newLimit;
    }

    /**
     * Checks if a given number is prime.
     * Extends the sieve if the number is greater than the current maximum.
     *
     * @param number the number to check for primality
     * @return true if the number is prime, false otherwise
     */
    public boolean isPrime(int number) {
        if (number > currentMax) {
            extendSieve(number);
        }
        return isPrime[number];
    }

    /**
     * Main method for testing the IncrementalSieve class.
     *
     * @param args command line arguments
     */
    public static void main(String[] args) {
        IncrementalSieve sieve = new IncrementalSieve(10);
        System.out.println(sieve.isPrime(11)); // true
        System.out.println(sieve.isPrime(4));  // false
        sieve.extendSieve(20);
        System.out.println(sieve.isPrime(19)); // true
    }
}