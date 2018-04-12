//
//  24.cpp
//  in loop, using constant space
//
//  Created by Ava on 2018/4/12.
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return head;
        else if(head->next == nullptr) return head; // it needs two judgement, can't merge them in one
        
        ListNode **pp = &head;
        ListNode *a = nullptr;
        ListNode *b = nullptr;
        while((a = *pp) && (b = a->next)){
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }
        
        return head;
    }
};
