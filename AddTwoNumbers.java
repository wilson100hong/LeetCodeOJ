
public class AddTwoNumbers {

	public static class ListNode {
		int val;
		ListNode next;

		ListNode(int x) {
			val = x;
			next = null;
		}
	};

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    
    	int carry = 0;
    	ListNode head = null, cur = null;
    	while (l1 != null || l2 != null || carry != 0) {
    		int val1 = l1 != null ? l1.val : 0;
    		int val2 = l2 != null ? l2.val : 0;
    		int sum = val1 + val2 + carry;
    		carry = sum / 10;
    		sum %= 10;

    		ListNode node = new ListNode(sum);
    	
    		if (head == null) {
    			head = node;
    		} else {
    			cur.next = node;
    		}
    		cur = node;
    		
    		if (l1 != null)
    			l1 = l1.next;
    		if (l2 != null)
    			l2 = l2.next;
    	}
    	
    	return head;
    }
    
    public static void dump(ListNode l) {
    	while (l != null) {
    		System.out.print(l.val + "->"); 
    		l = l.next;
    	}
    }
    
    public static ListNode feed(int[] array) {
    	ListNode head = null, cur = null;
    	for (int i = 0; i < array.length; ++i) {
    		ListNode node = new ListNode(array[i]);
    		if (head == null) {
    			head = node;
    		} else {
    			cur.next = node;
    		}
    		cur = node;
    	} 	
    	return head;  	
    }
    
	public static void main(String[] args) {
		AddTwoNumbers sol = new AddTwoNumbers();
		//dump(feed(new int[]{2,4,3}));

		dump(sol.addTwoNumbers(feed(new int[]{2,4,3}), feed(new int []{5,6,4})));
	}
}
