import java.util.Scanner;

class Node {
    String data;
    Node next;

    Node(String data) {
        this.data = data;
        this.next = null;
    }
}

public class Main {
    private Node head;

    public Main() {
        head = null;
    }

    private void addToEnd(String data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }

        Node currentNode = head;
        while (currentNode.next != null) {
            currentNode = currentNode.next;
        }
        currentNode.next = newNode;
    }

    private void removeFromFront() {
        if (head == null) {
            return;
        } else if (head.next == null) {
            head = null;
            return;
        } else {
            head = head.next;
        }
    }

    private void print() {
        if (head == null) {
            return;
        }
        Node current = head; // Use a temporary variable for clarity
        while (current != null) {
            System.out.println(current.data);
            current = current.next;
        }
    }

    public static void main(String[] args) {
        Main list = new Main();
        Scanner in = new Scanner(System.in);
        String[] input = in.nextLine().split(",");

        for (int iter = 0; iter < input.length; iter++) {
            String[] command = input[iter].split(" ");

            try {
                switch (command[0]) {
                    case "1":
                        list.addToEnd(command[1]);
                        break;
                    case "2":
                        list.removeFromFront();
                        break;
                    case "3":
                        list.print();
                        break;
                    // Ignore all other inputs.
                }
            } catch (Exception e) {
                // Ignore ERROR: IndexOutOfBoundsException
            }
        }
    }
}
