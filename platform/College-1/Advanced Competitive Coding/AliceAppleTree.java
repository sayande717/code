public class AliceAppleTree {
    static int minApples(int M, int K, int S, int W, int E) {
        // Calculate total apples available in the South
        int southApples = S * K;

        // If we can meet the requirement from South trees alone
        if (M <= southApples) {
            return M;
        }

        // Remaining apples needed after using South trees
        int remainingApples = M - southApples;

        // Total additional apples from East and West trees
        int eastWestApples = (W + E) * K;

        // Check if East and West trees can fulfill the remaining requirement
        if (remainingApples <= eastWestApples) {
            return southApples + remainingApples;
        }

        // If not enough apples are available
        return -1;
    }
    public static void main(String[] args) {
        // No. of red apples needed for the gift
        int M = 10;

        // No. of red apples per tree (in all directions)
        int K = 15;

        // No. of trees in different directions
        int S = 10; // South
        int W = 5; // West
        int E = 5; // East

        // Function Call
        int ans = minApples(M, K, S, W, E);
        System.out.println(ans);
    }
}