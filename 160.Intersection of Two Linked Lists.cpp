//
//  160.cpp
//
//  Created by Ava on 2018/5/1.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la=0,lb=0;
        ListNode* A = headA;
        ListNode* B = headB;
        while(A!=NULL){
            la++;
            A = A->next;
        }
        while(B!=NULL){
            lb++;
            B = B->next;
        }
        if(la>=lb){
            for(int i=0;i<(la-lb);i++)
                headA = headA->next;
        }
        if(lb>la){
            for(int i=0;i<(lb-la);i++)
                headB = headB->next;
        }
        while(headA != NULL && headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
