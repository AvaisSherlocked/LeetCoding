//
//  111.cpp
//  test3
//
//  Created by Ava on 2018/5/19.
//  Copyright © 2018年 Ava. All rights reserved.
//
/*Questions:
 Given a binary tree, find its minimum depth.
 The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

 Note: A leaf is a node with no children.
 Example:
 Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
 return its minimum depth = 2.
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
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return helper(root,0);
    }
    int helper(TreeNode* root, int count){
        if(root->left == NULL && root->right == NULL)
            return count+1;
        if(root->left == NULL) return helper(root->right,count+1);
        if(root->right == NULL) return helper(root->left,count+1);
        return min(helper(root->left,count+1),helper(root->right,count+1));
    }
};
