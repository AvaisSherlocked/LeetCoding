//
//  147.cpp
//  Created by Ava on 2018/4/18.
//  Copyright © 2018年 Ava. All rights reserved.
//

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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode Res(INT_MIN);
        ListNode* Iter = &Res;  // Use another List to record the sorted nodes
        while(head != nullptr){
            
            ListNode* tmp = head->next; // to record the next node to be compared
            Iter = &Res; // remember to make the Iter go back to the start
            while(Iter->next != nullptr && head->val > Iter->next->val) Iter = Iter->next;
            head->next = Iter->next;
            Iter->next = head;
            head = tmp;
            
        }
        
        return (&Res)->next;
    }
};
