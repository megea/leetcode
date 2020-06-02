/*
2. 两数相加

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//刚开始写的超时，明显不合理，需要优化
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *L1, *L2, *tmp;
    struct ListNode *res = NULL;

    L1 = l1;
    L2 = l2;

    int sum = 0;
    int index = 0;
    int multi, temp;
    
    while (L1 && L2) {
        multi = pow(10, index);
        if (L1) {
            sum += (L1->val * multi);
            L1 = L1->next;
        }
        if (L2) {
            sum += (L2->val * multi);
            L2 = L2->next;
        }
        index++;
    }

    if (sum == 0) {
        res = (struct ListNode*)malloc(sizeof(struct ListNode));
        res->val = 0;
        res->next = NULL;
        return res;
    }

    index--;

    while (sum) {
        multi = pow(10, index);
        //temp = sum % multi;
        temp = sum / multi;
        sum = sum % multi;

        tmp = (struct ListNode*)(void *)malloc(sizeof(struct ListNode));
        tmp->val = temp;
        tmp->next = NULL;

        if (!res) {
            res = tmp;
        } else {
            tmp->next = res;
            res = tmp;
        }
    }

    return res;
}



