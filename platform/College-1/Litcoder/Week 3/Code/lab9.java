import java.util.Scanner;

public class Main {
    // Charlie = 0, David = 1, NA = -1
    private byte findScorer(int score0, int score1) {
        if (score0 > score1) {
            return 0;
        } else if (score0 < score1) {
            return 1;
        } else {
            return -1;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Main ob = new Main();
        
        // Read inputs for Charlie and Dave
        String[] charlie = in.nextLine().split(" ");
        String[] dave = in.nextLine().split(" ");
        
        // ERROR in Submission: Both lengths should be 3.
        int lenCharlie = charlie.length;
        int lenDave = dave.length;
        
        int scoreCharlie = 0;
        int scoreDave = 0;
        
        // Error handling: If lengths are different, exit the program
        if (lenCharlie!=3 && lenDave!=3) {
            System.exit(0);
        }
        
        try {
            // Process the inputs
            for (int index = 0; index < lenCharlie; index++) {
                // Parse the scores for Charlie and Dave
                int score1 = Integer.parseInt(charlie[index]);
                int score2 = Integer.parseInt(dave[index]);

                // Check if scores are in the valid range (1 to 10)
                if (score1 < 1 || score1 > 10 || score2 < 1 || score2 > 10) {
                    System.exit(0);
                }

                // Use the findScorer method to determine who scores
                switch (ob.findScorer(score1, score2)) {
                    case 0:
                        scoreCharlie++;
                        break;
                    case 1:
                        scoreDave++;
                        break;
                }
            }
        } catch (Exception e) {
            System.exit(0);
        }

        // Output the results
        System.out.printf("%d %d", scoreCharlie, scoreDave);
        in.close();
    }
}
