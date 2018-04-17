//
//  155.cpp
//
//  Created by Ava on 2018/4/17.
//  Copyright © 2018年 Ava. All rights reserved.
//

class MinStack {
private:
    
public:
    stack<int> stack1;
    stack<int> stackMin;
    
    MinStack() {
        
    }
    
    void push(int x) {
        stack1.push(x);
        if(stackMin.empty()) stackMin.push(x);
        else{
            int Min = stackMin.top();
            if(Min < x)
                stackMin.push(Min);
            else
                stackMin.push(x);}
    }
    
    void pop() {
        if(!(stack1.empty() && stackMin.empty())){
            stack1.pop();
            stackMin.pop();
        }
    }
    
    int top() {
        return stack1.top();
    }
    
    int getMin() {
        if(!stackMin.empty())
            return stackMin.top();
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
