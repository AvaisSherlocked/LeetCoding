//
//  21.Merge Two Sorted Lists.cpp
//
//  Created by Ava on 2018/4/14.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == nullptr) return l2;  // the judgement of the nullptr
        if(l2 == nullptr) return l1;
        ListNode* phead = l1->val > l2->val ?l2:l1; // record the head
        
        while(l1 != nullptr || l2 != nullptr){
            if(l1->val <= l2->val){
                l1->next = mergeTwoLists(l1->next,l2);  // remember to compare current val of l2
                return l1;
            }
            else{
                l2->next = mergeTwoLists(l2->next,l1);
                return l2;
            }
        }
        
        return phead;
    }
};
