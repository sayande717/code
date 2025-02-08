import java.util.HashSet;
import java.util.Set;
import java.util.Scanner;

// Final sequences for 'ABC' = {"A", "AB", "ABC", "AC", "ACB", "B", "BA", "BAC", "BC", "BCA", "C", "CA", "CAB", "CB", "CBA"}

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String tiles = input.next();
        Set<String> sequences = new HashSet<>();
        generateSequences(tiles, "", sequences);
        System.out.print(sequences.size());
        input.close();
    }

    private static void generateSequences(String tiles, String current, Set<String> sequences) {
        if (!current.isEmpty()) {
            sequences.add(current);
        }
        for (int index = 0; index < tiles.length(); index++) {
            // Remove 1st character from tiles, add it to the end of current.
            generateSequences(tiles.substring(0, index) + tiles.substring(index + 1), current + tiles.charAt(index), sequences);
        }
    }
}
