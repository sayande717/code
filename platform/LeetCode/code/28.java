// 206. https://leetcode.com/problems/reverse-linked-list/

class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode current = head;
        ListNode previous = null, temp = null;
        // EDGE: Linked List does not exit, or it has only 1 element.
        if(current == null || current.next == null) {
            return current;
        }
        while(current != null) {
            next = current.next;
            current.next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }
}