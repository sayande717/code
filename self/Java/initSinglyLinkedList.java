class initSinglyLinkedList {
    private static class ListNode {
        private int data;
        private ListNode next;

        public ListNode(int data) {
            this.data = data;
            this.next = null;
        }
    }

    private ListNode head;

    public static void main(String[] args) {
        initSinglyLinkedList listClass = new initSinglyLinkedList();
        listClass.head = new ListNode(10);
        ListNode second = new ListNode(1);
        ListNode third = new ListNode(8);
        ListNode fourth = new ListNode(11);

        // Connect them
        listClass.head.next = second;
        second.next = third;
        third.next = fourth;

        // 10 -> 1 -> 8 -> 1m
    }
}
