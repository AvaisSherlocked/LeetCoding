//
//  82. Remove Duplicates from Sorted List II.cpp

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
        
        ListNode* dup = head;
        if(head->val == (head->next)->val){   // the case that the head value equals to next
            while(dup->val == (dup->next)->val){
                dup = dup->next;
                if(dup == nullptr || dup->next == nullptr) break;   // remember to count in the dup->next
            }
            if(dup == nullptr) return nullptr; //break out, it means they are same till the end, dup is the last nullptr
            else if(dup != nullptr) return deleteDuplicates(dup->next); //means the dup is now the first different begin value
        }
        
        else if(head->val != head->next->val) // the case that the head value is differet from the next
            head->next = deleteDuplicates(head->next);
        return head;
    }
};
