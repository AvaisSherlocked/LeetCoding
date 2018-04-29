//
//  101.cpp
//
//  Created by Ava on 2018/4/30.
//  Copyright © 2018年 Ava. All rights reserved.
//

// recursively
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return Recursive(root->left,root->right);
    }
    bool Recursive(TreeNode* left,TreeNode* right){
        if(left==NULL && right ==NULL) return true;
        else if(left == NULL || right ==NULL) return false;
        else{
            if(left->val != right->val) return false;
            return (Recursive(left->left,right->right) && Recursive(left->right,right->left)); // important
        }
    }
};

// iteratively
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        queue<TreeNode*> ql;
        queue<TreeNode*> qr;
        ql.push(root->left);
        qr.push(root->right);
        
        while(!ql.empty() && !qr.empty()){
            TreeNode* L = ql.front();
            TreeNode* R = qr.front();
            ql.pop();
            qr.pop();
            if(L == NULL && R == NULL) continue; // this continue is easy to be written as "return false"
            else if(L == NULL || R == NULL) return false;
            else if(L->val != R->val) return false;
            else{
                ql.push(L->left);
                ql.push(L->right);
                qr.push(R->right);
                qr.push(R->left);
            }
        }
        return true;
    }
    
};
