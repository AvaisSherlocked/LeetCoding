//
//  148.cpp
//  test2
//
//  Created by Ava on 2018/4/17.
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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next == nullptr) return head;
        
        // part 1: to sortList in binary tree order
        ListNode* slow = head;
        ListNode* fast = head->next; //it's important to set the faster in the next position, to avoid the single val list
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;   //fast is the latter part of list
        slow->next = nullptr;  //to cut down the latter part for head
        return MergeList(sortList(head),sortList(fast));
    }
    
    // part 2: merge the input 2 lists
    ListNode* MergeList(ListNode* l1,ListNode* l2){
        ListNode* cur = new ListNode(0);
        ListNode* pcur = cur;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val < l2->val){
                cur->next =l1;
                l1 = l1->next ;
            }
            else{
                cur->next =l2;
                l2 = l2->next ;
            }
            cur= cur->next;
        }
        if(l1 != nullptr)
            cur->next = l1;
        if(l2 != nullptr)
            cur->next = l2;
        return pcur->next;
    }
};
