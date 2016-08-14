package main.java;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/*
 * This is the answer of LeetCode;
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
       int carry =0;
 
        ListNode newHead = new ListNode(0);
        ListNode p1 = l1, p2 = l2, p3=newHead;
 
        while(p1 != null || p2 != null){
            if(p1 != null){
                carry += p1.val;
                p1 = p1.next;
            }
 
            if(p2 != null){
                carry += p2.val;
                p2 = p2.next;
            }
 
            p3.next = new ListNode(carry%10);
            p3 = p3.next;
            carry /= 10;
        }
 
        if(carry==1) 
            p3.next=new ListNode(1);
 
        return newHead.next;
    }
}
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
