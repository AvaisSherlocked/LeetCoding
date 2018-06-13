/* questions:
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode* walker = head;
        ListNode* runner = head;
        while(runner->next!=NULL && runner->next->next!=NULL) {  // especially important !! the judgement is runner->next and runner->next->next
            walker = walker->next;
            runner = runner->next->next;
            if(walker==runner) return true;
        }
        return false;
    }
};
/* don't know why this didn't work here but worked at my own sde */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         if(head==NULL) return false;
//         ListNode* walker = head;
//         while(head != NULL){
//             head = head->next;
//             if(head == walker) return true;
//         }
//         return false;
//     }
// };