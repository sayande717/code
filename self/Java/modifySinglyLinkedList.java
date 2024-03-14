class modifySinglyLinkedList {
    private static class ListNode {
        private int data;
        private ListNode next;

        public ListNode(int data) {
            this.data = data;
            this.next = null;
        }
    }

    private static ListNode head;

    public static void printList() {
        ListNode current = head;
        while (current!=null) {
           System.out.print(current.data+" ");
           current=current.next;
        }
        System.out.println();
    }

    private static void addToBeginning(int val) {
        ListNode newNode = new ListNode(val);

        if(head == null) {
            head = newNode;
            return;
        }
        newNode.next = head;
        head = newNode;
    }

    private static void addToEnd(int val) {
        ListNode newNode = new ListNode(val);
        ListNode current = head;

        if(head == null) {
            head = newNode;
            return;
        }

        while (current.next!=null) {
            current = current.next;
        }
        current.next = newNode;
    }

    private static void addAtPosition(int val, int position) {
        ListNode newNode = new ListNode(val);
        if(position == 1) {
            newNode.next = head;
            head = newNode;

            return;
        }

        ListNode previous = head;
        int counter = 1;
        while(counter<(position-1) && previous!=null) {
            previous = previous.next;
            counter++;
        }
        newNode.next = previous.next;
        previous.next = newNode;
    }

    private static void deleteAtPosition(int position) {
        if(position==1) {
            head=head.next;
            return;
        }

        ListNode previous = head;
        int counter = 1;
        
        while (counter<(position-1)) {
           previous=previous.next;
           counter++;
        }
        ListNode current=previous.next;
        previous.next=current.next;
    }
    
    private static void deleteHead() {
        head = head.next;
    }

    private static void deleteTail() {
        if(head==null || head.next==null) {
            head=null;
            return;
        }

        ListNode previous = head;
        ListNode current = head.next;

        while (current.next!=null) {
            previous = previous.next;
            current = current.next;
        }
        previous.next = null;
    }

    private static int searchNode(int target) {
        if(head==null) {
            return -1;
        }
        ListNode current = head;
        int position=1;
        while(current!=null) {
            if(current.data == target) {
                return position;
            }
            current = current.next;
            position++;
        }
        return -1;
    }

    private static void reverseList() {
        if(head.next == null) {
            return;
        }
    
        ListNode current = head;
        ListNode previous = null;
        ListNode next = null;
        
        while (current!=null) {
            next = current.next;        // next keeps track of the RHS node
            current.next = previous;    // current node now points to it's LHS node
            previous = current;         // previous switches position with current
            current = next;             // current switches position with next
        }

        head = previous;                // At the end, both current and next point to null. Previous points to the last node with all pointers reversed.
    }

    private static void removeDuplicates() {
        if(head.next == null) {
            return;
        }

        ListNode current = head;

        while(current.next!=null) {
            if(current.data == current.next.data) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }
    }

    private static ListNode findnthNodeFromEnd(int n) {
        
        if(n == 0) {
            return null;
        }

        ListNode p1 = head;
        ListNode p2 = head;
        int count=0;

        while(count<n) {
            // If p2 is null, it means the position is out of bounds for the linked list.
            // Example: In 5 6 7 10, elements only exist till n=4. For n=4, p2 will start at `10`
            if(p2==null) {
                return null;
            }
            p2 = p2.next;
            count++;
        }

        while(p2!=null) {
            p1 = p1.next;
            p2 = p2.next;
        }

        return p1; // p2 sits at null, p1 sits `n` positions before it.
    }

    public static void main(String[] args) {
        modifySinglyLinkedList listClass = new modifySinglyLinkedList();
        
        addToBeginning(5);
        addToBeginning(6);
        addToBeginning(6);     
        // 7 -> 6 -> 5 -> null
        addToEnd(8);
        // 7 -> 6 -> 5 -> 10 -> null
        System.out.print("Original list: "); printList();

        // addAtPosition(20,2);
        // deleteHead();
        // deleteTail();
        // deleteAtPosition(4);
        // System.out.println(searchNode(10));
        //reverseList();
        removeDuplicates();
        //System.out.println("3rd node from last: "+findnthNodeFromEnd(3).data);
        //
        System.out.print("Modified list: "); printList();
    }
}
