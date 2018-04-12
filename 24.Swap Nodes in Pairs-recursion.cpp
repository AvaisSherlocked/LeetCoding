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
        
        ListNode* phead = new ListNode(0);
        phead->next = head; //the head pointer to head
        swap(phead,head);
        return phead->next;
    }
    
    void swap(ListNode* second,ListNode* first){// the second maintain the major line, the first is the processed line
        if(first == nullptr)
            return;
        else if((first->next) == nullptr)
            return;
        ListNode* tmp = first->next;
        first->next = tmp->next; // the swapping
        tmp->next = first;   // the tmp in fact is the head
        second->next = tmp;  // connecting with the changed one
        second = (second->next)->next;// moving to the place
        swap(second,first->next);
    }
};
