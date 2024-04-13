class modify2SinglyLinkedList {
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

    private static Node mergeTwoLists(Node head1, Node head2) {
        Node current1 = head1;
        Node current2 = head2;

        // We're creating a new list with the dummy node.
        // The pointer is used to change what the current pointer points to.
        // At the end, we will return mergedList.next, which effectively excludes the dummy node.
        Node mergedList = new Node(0);
        Node mergedListPointer = mergedList;

        while(current1!=null && current2!=null) {
            if(current1.value <= current2.value) {
                mergedListPointer.next = current1;
                current1 = current1.next;
            } else {
                mergedListPointer.next = current2;
                current2 = current2.next;
            }
            mergedListPointer = mergedListPointer.next;
        }
        
        // If current1 still has nodes left, point the mergedList to the remaining elements.
        if(current1!=null) {
            mergedListPointer.next = current1;
        }
        // If current2 still has nodes left, point the mergedList to the remaining elements.
        if(current2!=null) {
            mergedListPointer.next = current2;
        }
        return mergedList.next;
    }

    private static Node add2Lists(Node head1,Node head2) {
        Node current1 = head1;
        Node current2 = head2;
        Node resultList = new Node(0);
        Node resultListPointer = resultList;
        int carry = 0;

        while(current1!=null && current2!=null) {
            int sum = current1.value + current2.value;
            if(sum>=10) {
                sum = sum%10;
            }

            resultListPointer.value = current1.value+current2.value+carry;

            current1 = current1.next;
            current2 = current2.next;
            resultListPointer = resultListPointer.next;
        }

        return resultList.next;
    }

    public static void main(String[] args) {
        modify2SinglyLinkedList ob = new modify2SinglyLinkedList();
        ob.head1 = new Node(3);
        ob.addToEnd(ob.head1,4);
        ob.addToEnd(ob.head1,3);
        printList(ob.head1);

        ob.head2 = new Node(5);
        ob.addToEnd(ob.head2,6);
        ob.addToEnd(ob.head2,4);
        ob.printList(ob.head2);

       ob.printList(ob.add2Lists(ob.head1,ob.head2));

        //ob.printList(mergeTwoLists(ob.head1,ob.head2));
    }
}
