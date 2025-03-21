import java.util.Scanner;
public class BoothsAlgorithm {
    public static int algorithm(int multiplicand, int multiplier) {
        int A = 0; // Accumulator (initially 0)
        int Q_1 = 0; // Q' (Previous bit, initially 0)
        int M = multiplicand; // Multiplicand
        int Q = multiplier; // Multiplier
        int count = 4; // Number of bits (simplified example)
        
        System.out.println("Step-by-step execution:");
        
        while (count > 0) {
            System.out.println("A: " + A + " Q: " + Q + " Q-1: " + Q_1);
            // (Q & 1) means the least significant bit of Q.
            if ((Q & 1) == 0 && Q_1 == 1) {
                A += M; 
                System.out.println("Adding M: " + M);
            // (Q & 1) means the least significant bit of Q.
            } else if ((Q & 1) == 1 && Q_1 == 0) {
                A -= M;
                System.out.println("Subtracting M: " + M);
            }
            
            // Arithmetic Right Shift (ARS)
            
            // (Q & 1) means the least significant bit of Q.
            Q_1 = (Q & 1); // Store LSB of Q before shift

            // Explanation of the following line:
            // 1. (Q >> 1): Shift Q right by 1 bit
            // 2. ((A & 1) << 3): Get the LSB of A and shift it to the MSB position
            // 3. |: Bitwise OR operation
            Q = (Q >> 1) | ((A & 1) << 3); // Shift Q right and set MSB from A
            
            A = A >> 1; // Arithmetic shift right
            
            count--; // Reduce count
        }

        // (A << 4) means shifting A to the left by 4 bits, then performing a bitwise OR operation with Q.
        int result = (A << 4) | Q;
        System.out.println("Final A: " + A + " Final Q: " + Q);
        return result;
    }

    public static void main(String[] args) {
       // Take inputs in binary, or convert them to binary
       Scanner in = new Scanner(System.in);
       System.out.print("Enter multiplier: "); int multiplier = in.nextInt();
       System.out.print("Enter multiplicand: "); int multiplicand = in.nextInt();
       System.out.println(algorithm(multiplier,multiplicand));
    
       in.close();
    }
}
