//
//  105.cpp
//
//  Created by Ava on 2018/5/13.
//  Copyright © 2018年 Ava. All rights reserved.
//
/*
 Given preorder and inorder traversal of a tree, construct the binary tree.
 
 Note:
 You may assume that duplicates do not exist in the tree.
 
 For example, given
 
 preorder = [3,9,20,15,7]
 inorder = [9,3,15,20,7]
 
Return the following binary tree:
     3
    / \
   9  20
  /  \
 15   7
*／
 
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,inorder,0,inorder.size(),0,preorder.size());
        // i -> the left index for half part  --(search in inorder)
        // j -> the right index for half part
        // bl -> the next val for left half part in preorder--(the root val for this half part)
        // br -> the next val for right half part in preorder
    }
    TreeNode* helper(vector<int>& preorder,vector<int>& inorder,int i, int j, int bl, int br){
        if(i>=br || bl>=br)
            return NULL;
        
        int mid = preorder[bl];
        auto mid_index = find(inorder.begin()+i,inorder.begin()+j,mid);
        int m_dis = mid_index-inorder.begin()-i;
        
        TreeNode* root = new TreeNode(mid);
        root->left = helper(preorder,inorder,i,i+m_dis,bl+1,bl+1+m_dis);
        root->right = helper(preorder,inorder,i+m_dis+1,j,bl+1+m_dis,br);
        
        return root;
    }
};
