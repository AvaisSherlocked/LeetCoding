//
//  106.cpp
//  test3
//
//  Created by Ava on 2018/5/19.
//  Copyright © 2018年 Ava. All rights reserved.
//
/*question
 inorder = [9,3,15,20,7]
 postorder = [9,15,7,20,3]
 Return the following binary tree:
     3
    / \
   9  20
     /  \
    15   7
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
    TreeNode* helper(vector<int>& in,vector<int>& post,int is,int ie,int ps,int pe){
        if(ps>pe) return NULL;
        
        auto index = find(in.begin()+is,in.begin()+ie,post[pe]);
        int dis = index-in.begin();
        
        TreeNode* T = new TreeNode(post[pe]);
        T->left = helper(in,post,is,dis-1,ps,ps-is+dis-1);
        T->right = helper(in,post,dis+1,ie,pe-ie+dis,pe-1);
        return T;
    }
};
