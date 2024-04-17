// As opposed to a singly linked list, in this version, there is a pointer to the previous as well as next node.
// [Node] <-> [Node] <-> [Node]
// [PreviousPtr|Node|NextPtr] <-> [PreviousPtr|Node|NextPtr] <-> [PreviousPtr|Node|NextPtr]

public class initDoublyLinkedList {
    
    private class Node {
        private Node previous;
        private Node next;
        private int data;
        public Node(int data) {
            this.data = data;
            this.previous = null;
            this.next = null;
        }
    }

    private Node head;
    private Node tail;
    private Node listLength;

    public initDoublyLinkedList() {
        this.head = null;
        this.tail = null;
        this.listLength = 0;
    }

    public boolean isEmpty() {
        return (head==null);
    }

    public int length() {
        return listLength;
    }

    public void printListForward() {
        Node current = head;
        if(head==null) {
            return;
        }
        while(current!=null) {
            System.out.print(current.data+" <-> ");
            current=current.next;
        }
        System.out.println();
    }

    public void printListBackward() {
        Node current = tail;
        if(tail==null) {
            return;
        }
        while(current!=null) {
            System.out.print(current.data+" <-> ");
            current=current.previous;
        }
        System.out.println();
    }

    public static void main(String[] args) {
            
    }
}
