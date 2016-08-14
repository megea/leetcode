package main.java;

/**
 * 2. Add Two Numbers
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.

 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

public class AddTwoNumbers {

	/**
	 * @param argss
	 */
	public ListNode addTwoNumbers(ListNode l1, ListNode l2){
		int carry = 0;
		int sum = 0;
		ListNode listRet = new ListNode(0);
		ListNode listTemp = listRet;
		
		if (null == l1) listTemp = l2;
		if (null == l2) listTemp = l1;
		
		while ((null != l1) && (null != l2)){	//两个链表一样长时
			sum = l1.val + l2.val + carry;
			carry = sum / 10;
			listTemp.next = new ListNode(sum % 10);
			listTemp = listTemp.next;
			l1 = l1.next;
			l2 = l2.next;
			
		}
		while (null != l1){		//两个链表不一样长时
			sum = l1.val + carry;
			carry = sum / 10;
			listTemp.next = new ListNode(sum % 10);
			listTemp = listTemp.next;
			l1 = l1.next;
		}
		while (null != l2){
			sum = l2.val + carry;
			carry = sum / 10;
			listTemp.next = new ListNode(sum % 10);
			listTemp = listTemp.next;
			l2 = l2.next;
		}
		if (carry == 1)		//最后一位有进位时
			listTemp.next = new ListNode(1);
		return listRet.next;	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
