//
//  19.cpp

//  Created by Ava on 2018/4/11.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* phead = head;  // record the first head
        ListNode* headfirst = head;  //counting n
        for(int i=0;i<n;i++){
            headfirst = headfirst->next;
        }
        if(headfirst == nullptr) return phead->next;  //incase that n is equal to the total num
        while(headfirst->next != nullptr){
            headfirst = headfirst->next;
            head = head->next;
        }
        head->next = (head->next)->next;
        
        return phead;
    }
};
