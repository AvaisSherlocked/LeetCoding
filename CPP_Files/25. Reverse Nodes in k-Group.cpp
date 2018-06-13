/* quesitons:
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/* soution1:
iteratively, only use vector, stack to store nodes.
1. every k nodes in head list were reversed by self-defined function reverse
2. link up all lists fragment to one in the res vector
// 23 ms
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k<=1) return head;
        vector<ListNode*> res;
        ListNode* pp = head; // for the situation of no reverse 
        while(head != NULL){
            ListNode* p = head;
            ListNode* p2 = p;
            int i=1;
            while(i<k){
                if(p2->next == NULL) break;
                p2 = p2->next;
                i++;
            }
            if(i==k){
                head = p2->next;
                p2->next=NULL;
                res.push_back(reverse(p));
            }
            else{
                res.push_back(p);
                head = NULL;
            }
        }
        // link up
        if(res.empty()) return pp;
        ListNode* phead = res[0];
        for(int i=0;i<res.size()-1;i++){
            while(res[i]->next) res[i] = res[i]->next;
            res[i]->next = res[i+1];
        }
        return phead;
    }
    // reverse the whole list of input
    ListNode* reverse(ListNode* head){
        stack<ListNode*> Q;
        while(head!=NULL){
            Q.push(head);
            head = head->next;
        }
        ListNode* pnew = Q.top();
        while(Q.size()>1){
            ListNode* tmp1=Q.top();
            Q.pop();
            ListNode* tmp2=Q.top();
            tmp1->next = tmp2;
        }
        ListNode* tmp = Q.top();
        tmp->next = NULL;
        return pnew;
    }
};

/* recursively */
/* 
There are one more node being input to the reverse.
so that in main recursive function, phead -> next = reverseKGroup(x,y) can be implemented
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* phead = head;  // e.g.phead = 1
        for(int i=0;i<k;i++){
            if(head == NULL) return phead;
            head = head->next;
        }
        ListNode* res = reverse(phead,head);
        phead->next = reverseKGroup(head,k);  // this phead is the one node in front of last node in reversed list,
                                             // the last node will be replaced after this step
        return res;
    }
    // reverse the list in front of tail, e.g. [1-2-3-4-5] -> [4-3-2-1-5], prev=4
    ListNode* reverse(ListNode* head,ListNode* tail){
        ListNode* prev = tail;
        while(head!=tail){
            ListNode* tmp= head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
};
