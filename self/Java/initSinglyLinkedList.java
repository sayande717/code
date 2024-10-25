// A singly linked list contains nodes, where one node points to the next one.
// [Node] -> [Node] -> [Node]
// [Node|NextPtr] -> [Node|NextPtr] -> [Node|NextPtr]
class initSinglyLinkedList {
    private static class ListNode {
        private int data;
        private ListNode next;

        public ListNode(int data) {
            this.data = data;
            this.next = null;
        }
    }

    private static ListNode head;

    // Iterate from head, continue till the node is null (the last node points to null)
    private static void printList() {
        ListNode current = head;
        while (current!=null) {
           System.out.print(current.data+" ");
           current=current.next;
        }
        System.out.println();
    }

    private static int findLengthOfList() {
        int count=0;
        ListNode current = head;
        while (current!=null) {
            count++;
            current=current.next;
        }
        return count;
    }

    public static void main(String[] args) {
        initSinglyLinkedList listClass = new initSinglyLinkedList();

        listClass.head = new ListNode(10);
        ListNode second = new ListNode(1);
        ListNode third = new ListNode(8);
        ListNode fourth = new ListNode(11);

        // Connect the nodes
        listClass.head.next = second;
        second.next = third;
        third.next = fourth;

        // 10 -> 1 -> 8 -> null
        //
        printList();

        System.out.println("Length: "+findLengthOfList());
    }
}
