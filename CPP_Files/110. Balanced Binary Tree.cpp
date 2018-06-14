//
//  110.cpp
//
//  Created by Ava on 2018/5/14.
//  Copyright © 2018年 Ava. All rights reserved.
/*
 Given a binary tree, determine if it is height-balanced.
 For this problem, a height-balanced binary tree is defined as:
 
 a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 Example 1:
    Given the following tree [3,9,20,null,null,15,7]:
       3
      / \
     9  20
       /  \
      15   7
 Return true.
 Example 2:
 Given the following tree [1,2,2,3,3,null,null,4,4]:
         1
        / \
       2   2
      / \
     3   3
    / \
   4   4
 Return false.
 Example 3:
 Given the following tree [1,2,2,3,null,null,3,4,null,null,null,null,null,null,4]:
          1
         / \
        2   2
       /     \
      3       3
     /         \
    4           4
 Return false.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// nested recursive functions
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        if(abs(helper(root->left,1)-helper(root->right,1))>1) return false;
        return (isBalanced(root->left) && isBalanced(root->right));
    }
    int helper(TreeNode* root, int height){ // to count the root maximum depth
        if(root == NULL) return height;
        if(root->left == NULL && root->right == NULL) return height+1;
        if(root->left != NULL && root->right == NULL) return helper(root->left,height+1);
        if(root->left == NULL && root->right != NULL) return helper(root->right,height+1);
        int L = helper(root->left,height+1);
        int R = helper(root->right,height+1);
        return L>R?L:R;
    }
};
