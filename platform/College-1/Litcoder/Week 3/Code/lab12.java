import java.util.Scanner;

class CustomStack {
    private String last = new String("");
    private String file = new String("");

    // Inserts a string of characters at the current cursor position in the text
    protected void insert(String value) {
        last = file;
        file = file + value;
    }

    // Deletes the last `value` characters from the text
    protected void delete(int value) {
        if (value > file.length()) {
            value = file.length(); // Ensure value is not greater than the file length
        }
        last = file;
        file = file.substring(0, file.length() - value);
    }

    // Retrieves the character at index `value` from the text and returns it
    protected char get(int value) {
        return file.charAt(value - 1); // Convert to 0-based index
    }

    // Reverts the last executed command on the text
    protected void undo() {
        file = last;
    }

    // Prints the current state of the text
    protected void print() {
        System.out.println(file);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        CustomStack ob = new CustomStack();

        // Read commands, split by ','
        String[] commands = in.nextLine().split(",");

        // Process each command
        for (int command = 0; command < commands.length; command++) {
            String[] cmd = commands[command].split(" ");
            int choice = Integer.parseInt(cmd[0]);

            // Insert operation
            if (choice == 1) {
                String value = cmd[1];
                ob.insert(value);
            } else {
                // Parse the integer value from the second part of the command
                int value = Integer.parseInt(cmd[1]);
                switch (choice) {
                    case 2: // Delete operation
                        ob.delete(value);
                        break;
                    case 3: // Get operation
                        char result = ob.get(value);
                        System.out.println(result);
                        break;
                    case 4: // Undo operation
                        ob.undo();
                        ob.print();
                        break;
                }
            }
        }

        in.close();
    }
}
