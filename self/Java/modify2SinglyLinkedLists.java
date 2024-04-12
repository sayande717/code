class modifySinglyLinkedList2 {
    private static class Node {
        int value;
        Node next;
        Node(int value) {
            this.value=value;
            this.next = null;
        }
    }

    Node head1;
    Node head2;
    Node head3;

    private static void addToEnd(Node head, int data) {
        Node newNode = new Node(data);
        Node current = head;

        if(head == null) {
            head = newNode;
            System.out.print(head.value);
            return;
        }

        while(current.next!=null) {
            current = current.next;
        }

        current.next = newNode;
    }

    private static void printList(Node head) {
        Node current = head;
        while(current!=null) {
            System.out.print(current.value+" -> ");
            current = current.next;
        }

        System.out.println();
    }

    private static void mergeTwoLists() {
        modifySinglyLinkedList2 ob = new modifySinglyLinkedList2();
        Node current1 = ob.head1;
        Node current2 = ob.head2;
        while(current1!=null && current2!=null) {
            if(current1.value <= current2.value) {
                addToEnd(ob.head3,current1.value);
                current1 = current1.next;
            } else {
                addToEnd(ob.head3,current2.value);
                current2 = current2.next;
            }
        }

        while(current1!=null) {
            addToEnd(ob.head3,current1.value);
            current1 = current1.next;
        }

        while(current2!=null) {
            addToEnd(ob.head3,current2.value);
            current2 = current2.next;
        }
    }

    public static void main(String[] args) {
        modifySinglyLinkedList2 ob = new modifySinglyLinkedList2();
        ob.head1 = new Node(12);
        ob.addToEnd(ob.head1,23);
        ob.addToEnd(ob.head1,24);
        printList(ob.head1);

        ob.head2 = new Node(10);
        ob.addToEnd(ob.head2,13);
        ob.addToEnd(ob.head2,14);
        ob.printList(ob.head2);

        mergeTwoLists();
        ob.printList(ob.head3);
    }
}
