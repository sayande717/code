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

    private static void insertInSortedList(int data) {
        ListNode newNode = new ListNode(data);

        if(head.data > newNode.data) {
            newNode.next = head;
            head = newNode;
            return;
        }

        ListNode current = head;
        ListNode previous = null;
        
        // current!=null: when the data is larger than all elements in linked list.
        while(current!=null && current.data<newNode.data) {
            previous = current;
            current = current.next;
        }

        previous.next = newNode;
        newNode.next = current;
    }
    
    private static void removeNode(int data) {
        ListNode previous = null;
        ListNode current = head;
        if(head.data == data) {
            head = head.next;
            return;
        }

        while(current != null) {
            if(current.data == data) {
                previous.next = current.next;
                return;
            }
            previous = current;
            current = current.next;

        }
    }
    
    public static void createLoop() {
        ListNode first = new ListNode(1);
        ListNode second = new ListNode(2);
        ListNode third = new ListNode(3);
        ListNode fourth = new ListNode(4);
        ListNode fifth = new ListNode(5);
        ListNode sixth = new ListNode(6);

        head = first;
        first.next = second;
        second.next = third;
        third.next = fourth;
        fourth.next = fifth;
        fifth.next = sixth;
        sixth.next = third;
    }

    public static boolean detectLoop() {
        // Logic: There are 2 pointers, slow & fast. Slow moves 1 step ahead, Fast moves 2 steps ahead.
        // In case a loop exists, the fast pointer will definitely meet the slow pointer, and that's what we want to detect.
        ListNode slowPtr = head;
        ListNode fastPtr = head;
        // fastPtr!=null: If fastPtr is in 2nd last position, it'll move to null.
        // fastPtr.next!=null: If fastPtr is in last position, it's next element will be null, so fastPtr.next.next will return a null pointer exception.
        while(fastPtr != null && fastPtr.next != null) {
            slowPtr = slowPtr.next;
            fastPtr = fastPtr.next.next;

            if(slowPtr == fastPtr) {
                // System.out.println(detectStartOfLoop(slowPtr).data);
                // breakLoop(slowPtr);
                return true;
            }
        }

        return false;
    }

    // To detect start of the loop, we create a new pointer and traverse from the head of the loop. We also keep moving the slow pointer. The point where they meet is the starting point of the loop.
    // This is called `Floyd's Cycle Detection Algorithm`.
    public static ListNode detectStartOfLoop(ListNode slowPtr) {
        ListNode Ptr = head;
        while(Ptr != slowPtr) {
            Ptr = Ptr.next;
            slowPtr = slowPtr.next;
        }
        return Ptr;
    }
    
    // We move till 1 step before Ptr & slowPtr meet. Then, we just break the link between slowPtr and the start of the loop.
    public static void breakLoop(ListNode slowPtr) {
        ListNode Ptr = head;
        while(slowPtr.next != Ptr.next) {
            Ptr = Ptr.next;
            slowPtr = slowPtr.next;
        }

        slowPtr.next = null;
    }

    public static void main(String[] args) {
        
        addToBeginning(7);
        addToBeginning(6);
        addToBeginning(5);     
        // 7 -> 6 -> 5 -> null
        addToEnd(8);
        addToEnd(9);
        addToEnd(10);

        // 7 -> 6 -> 5 -> 10 -> null
        System.out.print("Original list: "); printList();

        // addAtPosition(20,2);
        // deleteHead();
        // deleteTail();
        // deleteAtPosition(4);
        // System.out.println(searchNode(10));
        //reverseList();
        //removeDuplicates();
        //System.out.println("3rd node from last: "+findnthNodeFromEnd(3).data);
        //insertInSortedList(11);
        //removeNode(6);
        
        // createLoop(); // WARN: Deletes existing data.
        System.out.println("Loop: "+detectLoop());
        System.out.print("Modified list: "); printList();
    }
}
