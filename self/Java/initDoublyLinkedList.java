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
    private int listLength;

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

    public void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        Node current = head;

        if(isEmpty()) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode.next = current;
        current.previous = newNode;
        head = newNode;
    }
    
    public void insertAtEnd(int data) {
        Node newNode = new Node(data);

        if(isEmpty()) {
            head = newNode;
            tail = newNode;
            return;
        }

        Node current = tail;
        newNode.previous = current;
        current.next = newNode;
        tail = newNode;
    }

    public void deleteFirst() {
        if(head==null) {
            return;
        }

        Node current = head;
        if(head.next==null) {
            head = null;
            tail = null;
            return;
        }

        // Break the pointers on both sides.
        current.next.previous = null;
        head = current.next;
        current.next = null;
    }

    public void deleteLast() {

        if(tail==null) {
            return;
        }
        
        Node current = tail;
        
        if(tail.previous==null) {
            head = null;
            tail = null;
            return;
        }

        current.previous.next = null;
        tail=current.previous;
        current.previous = null;
    }


    public static void main(String[] args) {
        initDoublyLinkedList ob = new initDoublyLinkedList();

        for(int nodeData = 5;nodeData>=0;nodeData--) {
            ob.insertAtBeginning(nodeData);
            //ob.insertAtEnd(nodeData);
        }

        //ob.deleteFirst();
        ob.deleteLast();

        ob.printListForward();
        ob.printListBackward();
    }
}
