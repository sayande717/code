class modifyLinkedList {
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

    public static void main(String[] args) {
        modifyLinkedList listClass = new modifyLinkedList();
        
        addToBeginning(5);
        addToBeginning(6);
        addToBeginning(7);     
        // 7 -> 6 -> 5 -> null
        
        addToEnd(10);
        // 7 -> 6 -> 5 -> 10 -> null
        printList();
    }
}
