//
//  199.cpp
//
//  Created by Ava on 2018/5/7.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(root,res,1); // l is the level of tree
        return res;
    }
    void helper(TreeNode* root, vector<int> &res,int l){
        if(root == NULL) return;
        if(root!=NULL && res.size()<l){
            res.push_back(root->val);
        }
        helper(root->right,res,l+1);
        helper(root->left,res,l+1);
    }
};
