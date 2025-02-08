
import java.util.Scanner;
public class Main {
    // Method to handle wrong IP Address input
    private void wrongIP() {
        System.out.print("Wrong IP Address");
        System.exit(0);
    }

    // Method to determine the class of the IP address segment
    private char getClass(int num) {
        if (num >= 0 && num <= 63) {
            return 'L';
        } else if (num >= 64 && num <= 127) {
            return 'M';
        } else if (num >= 128 && num <= 191) {
            return 'N';
        } else if (num >= 192 && num <= 255) {
            return 'P';
        } else {
            // ERROR: IP Address isn't within range
            return 'Z';
        }
    }

    public static void main(String[] args) {
        Main ob = new Main();
        Scanner in = new Scanner(System.in);
        
        // Read and trim the full IP address input
        String fullIP = in.nextLine().trim();
        char classIP = 'Z';

        // ERROR: Overall length isn't within range
        if (fullIP.length() < 7 || fullIP.length() > 15) {
            ob.wrongIP();
        }

        // Split the IP address into segments
        String[] arrIP = fullIP.split("\\.", 4);

        // ERROR: There are less/more segments than expected
        int segments = arrIP.length;
        if (segments != 4) {
            ob.wrongIP();
        }

        // Loop through the IP address segments and determine the class
        for (int segment = 0; segment < segments; segment++) {
            try {
                int current = Integer.parseInt(arrIP[segment]);
                char tempclassIP = ob.getClass(current);

                // ERROR: IP Segment isn't within range
                if (tempclassIP == 'Z') {
                    ob.wrongIP();
                }

                // Assign the class based on the second segment of the IP
                if (segment == 1) {
                    classIP = tempclassIP;
                }
            } catch (Exception e) {
                ob.wrongIP();
            }
        }

        // Print the determined IP class
        System.out.printf("Class %c", classIP);
        in.close();
    }
}

