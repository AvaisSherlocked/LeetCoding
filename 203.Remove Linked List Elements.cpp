//
//  203.cpp
//  test3
//
//  Created by Ava on 2018/5/20.
//  Copyright © 2018年 Ava. All rights reserved.
//

/*questions:
 Remove all elements from a linked list of integers that have value val.
 e.g.
 Input:  1->2->6->3->4->5->6, val = 6
 Output: 1->2->3->4->5
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* res = new ListNode(-1);
        ListNode* head2 = res;  // use head2 to denote the node before the head
        res->next = head;
        while(head != NULL){
            if(head->val == val){
                head2->next = head->next;
                head = head->next;
                head2->next = head; // head2->next is head
            }
            else{
                head = head->next;
                head2 = head2->next;
            }
        }
        return res->next;
    }
};
