//
//  100.cpp
//
//  Created by Ava on 2018/4/18.
//  Copyright © 2018年 Ava. All rights reserved.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        if(!((p==nullptr && q==nullptr)||(p!=nullptr && q!=nullptr))) return false;
        if(p->val != q->val) return false;
        bool Left = true;
        bool Right = true;
        if(p->left || q->left){  // incase that p only has left and q only has right
            Left = isSameTree(p->left,q->left);
        }
        if(p->right || q->right) {
            Right = isSameTree(p->right,q->right);
        }
        return(Left && Right);
    }
};
