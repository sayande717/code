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

    public static void main(String[] args) {
        modifySinglyLinkedList listClass = new modifySinglyLinkedList();
        
       addToBeginning(5);
       addToBeginning(6);
       addToBeginning(7);     
        // 7 -> 6 -> 5 -> null
        addToEnd(10);
        // 7 -> 6 -> 5 -> 10 -> null
        printList();        

        // addAtPosition(20,2);
        // deleteHead();
        // deleteTail();
        // deleteAtPosition(4);
        // System.out.println(searchNode(10));

        printList();
    }
}
