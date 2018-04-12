//
//  Swap Nodes in Pairs.cpp
//  recursion version
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
        
        ListNode* Next = head->next;
        head->next = swapPairs(Next->next);
        Next->next = head;
        
        return Next;
    }
};
