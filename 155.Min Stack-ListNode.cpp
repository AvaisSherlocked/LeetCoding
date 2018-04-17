//
//  155.cpp
//
//  Created by Ava on 2018/4/17.
//  Copyright © 2018年 Ava. All rights reserved.
//

class MinStack {
    
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x): val(x),next(NULL){}
    };
    
    ListNode* head=NULL;
    MinStack() {
        
    }

    void push(int x) {
        ListNode* top = new ListNode(x);
        top->next = head;  // add in from the former
        head = top;
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        ListNode* tmp = head;
        int Min = tmp->val;
        while(tmp){
            if(tmp->val<Min) Min = tmp->val;
            tmp = tmp->next;
        }
        return Min;
    }
};
