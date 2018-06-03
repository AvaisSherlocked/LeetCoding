//
//  104.cpp
//
//  Created by Ava on 2018/4/21.
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
    int sum=0;
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        else if(root->left && root->right == NULL) sum =1+ maxDepth(root->left);
        else if(root->right && root->left == NULL) sum =1+ maxDepth(root->right);
        else sum = 1+ max(maxDepth(root->left),maxDepth(root->right));
        return sum;
    }
};
