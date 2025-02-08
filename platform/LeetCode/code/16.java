// 21. https://leetcode.com/problems/merge-two-sorted-lists/

public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode outList = new ListNode(0);
        ListNode head = outList;
        while(list1 != null && list2 != null) {
            if(list1.val <= list2.val) {
                outList.next = list1;
                list1 = list1.next;
            } else {
                outList.next = list2;
                list2 = list2.next;
            }

            outList = outList.next;
        }

        while(list1 != null) {
            outList.next = list1;
            outList = outList.next;
            list1 = list1.next;
        }

        while(list2 != null) {
            outList.next = list2;
            outList = outList.next;
            list2 = list2.next;
        }

        return head.next;
    }
}