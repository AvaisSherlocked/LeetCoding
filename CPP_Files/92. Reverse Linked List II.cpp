/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* p=head;
        int i=1;
        ListNode* prev=head;
        while(i<m){
            prev = head;
            head = head->next;
            i++;
        }
        ListNode* tmp=head;
        while(i<n){
            tmp = tmp->next;
            i++;
        }
        ListNode* post = tmp->next;
        tmp->next = NULL;
        ListNode* rev = reverse(head);
        head->next = post;
        if(m>1) prev->next = rev;
        else p=rev;
        return p;
    }
    ListNode* reverse(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* p = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};