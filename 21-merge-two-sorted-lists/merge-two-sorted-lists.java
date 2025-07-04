
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        
        ListNode t1=list1;
        ListNode t2=list2;
        ListNode dummy = new ListNode(-1);
        ListNode t3=dummy;
               while(t1!=null&&t2!=null){
            if(t1.val<t2.val){
                t3.next = t1;
                t1 = t1.next;

            }
            else{
                t3.next = t2;
                t2 = t2.next;
            }
            t3 = t3.next;

        }
        if(t1 == null){
            t3.next = t2;
        }
        if(t2 == null){
            t3.next = t1;
        }
        return dummy.next;


    }
}