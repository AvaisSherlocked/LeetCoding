//
//  102.cpp
//
//  Created by Ava on 2018/4/30.
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

// iteratively --6ms
 class Solution {
 public:
     vector<vector<int>> levelOrder(TreeNode* root) {
         queue<TreeNode*> q;
         vector<vector<int>> res;
         if(root==NULL) return res;

         res.push_back(vector<int>(1,root->val));
         q.push(root->left);
         q.push(root->right);
         int level = 0;

         int count=2,count2=0;
         while(!q.empty()){
             vector<int> Le;
             count2 = 0;
             for(int k=0;k<count;k++){
                 TreeNode* cur = q.front();
                 if(cur!=NULL){
                     count2++;
                     Le.push_back(cur->val);
                     q.push(cur->left);
                     q.push(cur->right);
                 }
                 q.pop();
                 if(q.empty()) break;
             }
             if(!Le.empty())
                 res.push_back(Le);
             count = 2*count2;
         }
         return res;
     }
 };

// recursively --6ms
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) return res;
        helper(root,res,1);
        return res;
    }
    void helper(TreeNode* root, vector<vector<int>> &res,int level){
        if(res.size()<level)
            res.push_back(vector<int>(1,root->val));
        else
            res[level-1].push_back(root->val);
        if(root->left != NULL) helper(root->left,res,level+1);
        if(root->right != NULL) helper(root->right,res,level+1);
        return;
    }
};
