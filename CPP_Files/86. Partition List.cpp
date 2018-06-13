/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* L=new ListNode(-1);
        ListNode* L2 = L;
        ListNode* G=new ListNode(-1);
        ListNode* G2 = G;
        while(head != NULL){
            if(head->val < x){
                L->next = head;
                L = L->next;
            }
            else{
                G->next = head;
                G = G->next;
            }
            head = head->next;
        }
        G->next = NULL;
        L->next = G2->next;
        return L2->next;
    }
};