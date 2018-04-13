//
//  83. Remove Duplicates from Sorted List.cpp
//
//  Created by Ava on 2018/4/13.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        if(head->next == nullptr)
            return head;
        
        ListNode* Dup = head->next;
        while(head->val == Dup->val){
            Dup = Dup->next;
            if(Dup == nullptr) break;
        }
        head->next = deleteDuplicates(Dup);
        return head;
    }
};
