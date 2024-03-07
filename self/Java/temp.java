class temp {
    public static class ListNode {
        private static int data;
        private static ListNode next;
        ListNode(int data) {
            this.data = data;
            this.next = null;
        }
    }

    private static ListNode head;

    private static void printList() {
        ListNode current = head;
        while(current!=null) {
            System.out.print(current.data+" ");
            current=current.next;
        }
    }

    public static void main(String[] args) {
        temp ob = new temp();
        ob.head = new ListNode(8);
        ListNode node2 = new ListNode(10);
        ListNode node3 = new ListNode(1);
        ob.head.next = node2;
        node2.next = node3;

        printList();
    }
}
