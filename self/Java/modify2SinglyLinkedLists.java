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

        // 943 + 465 = 1408. After 9 + 4+ (carry) 1 = 14 is done, 4 is going to be inserted in the while loop.
        // But, the last carry bit (1) will not be inserted, so it is done manually after the loop ends.
        while(current1!=null || current2!=null) {
            // Take digits only when they are non-zero, otherwise assume 0.
            int digit1 = (current1!=null)?current1.value:0;
            int digit2 = (current2!=null)?current2.value:0;
            // We have to recalculate sum (sum%10) afterwards, and then insert it, because we need the original value of sum for the intermediate calculations.
            int sum = digit1 + digit2 + carry;
            // If sum = 9 + 4 + (carry) 0 = 14, 4 is inserted, while 1 becomes carry.
            // Carry: 14 / 10 = 1, and Sum: 14 % 10 = 4
            carry = sum/10;

            resultListPointer.next = new Node(sum%10);

            if(current1!=null) {
                current1 = current1.next;
            }

            if(current2!=null) {
                current2 = current2.next;
            }

            resultListPointer = resultListPointer.next;
        }

        if(carry>0) {
            resultListPointer.next = new Node(carry);
        }
        return resultList.next;
    }

    public static void main(String[] args) {
        modify2SinglyLinkedList ob = new modify2SinglyLinkedList();
        ob.head1 = new Node(3);
        ob.addToEnd(ob.head1,4);
        ob.addToEnd(ob.head1,9);
        printList(ob.head1);

        ob.head2 = new Node(5);
        ob.addToEnd(ob.head2,6);
        ob.addToEnd(ob.head2,4);
        ob.printList(ob.head2);

       ob.printList(ob.add2Lists(ob.head1,ob.head2));

        //ob.printList(mergeTwoLists(ob.head1,ob.head2));
    }
}
