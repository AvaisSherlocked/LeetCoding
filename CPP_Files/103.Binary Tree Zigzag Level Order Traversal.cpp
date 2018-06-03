//
//  103.cpp
//
//  Created by Ava on 2018/5/12.
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
/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to
left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
     3
    / \
   9  20
     /  \
    15   7
 return its zigzag level order traversal as:
 [
    [3],
    [20,9],
    [15,7]
 ]
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

// do not use reverse
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root == NULL) return res;
        q.push(root);
        int l=0;
        while(!q.empty()){
            int s = q.size();
            vector<int> res_tmp(s,-1);
            for(int i=0;i<s;i++){
                TreeNode* tmp = q.front();
                if(l%2)
                    res_tmp[s-1-i]=tmp->val;
                else
                    res_tmp[i]=tmp->val;
                if(tmp->left != NULL) q.push(tmp->left);
                if(tmp->right != NULL) q.push(tmp->right);
                q.pop();
            }
            // if(l%2) reverse(res_tmp.begin(),res_tmp.end());
            res.push_back(res_tmp);
            l++;
        }
        return res;
    }
};
// oringinal
 class Solution {
 public:
     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> res;
         queue<TreeNode*> q;
         if(root == NULL) return res;
         q.push(root);
         int l=0;
         while(!q.empty()){
             vector<int> res_tmp;
             queue<TreeNode*> q2=q;
             while(!q2.empty()){
                 TreeNode* tmp = q2.front();
                 res_tmp.push_back(tmp->val);
                 if(tmp->left != NULL) q.push(tmp->left);
                 if(tmp->right != NULL) q.push(tmp->right);
                 q.pop();
                 q2.pop();
             }
             if(l%2) reverse(res_tmp.begin(),res_tmp.end());
             res.push_back(res_tmp);
             l++;
         }
         return res;
     }
 };

