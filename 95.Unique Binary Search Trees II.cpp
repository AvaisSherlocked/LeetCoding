//
//  95.cpp
//
//  Created by Ava on 2018/4/23.
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
    vector<TreeNode*> generateTrees(int n) {
        return generate(n);
    }
    vector<TreeNode*> generate(int n){
        vector<TreeNode*> res;
        if(n==0) return res;
        res.push_back(new TreeNode(1));
        if(n==1) return res;
        
        for(int i=2;i<=n;i++){
            vector<TreeNode*> tmp;
            TreeNode* newNode = new TreeNode(i);
            for(int j=0;j<res.size();j++){
                TreeNode* copy = copytree(res[j]);
                newNode = new TreeNode(i);  // very important to update
                newNode->left = copy;
                tmp.push_back(newNode);  // push in the first kind
                
                copy = copytree(res[j]);  //reload the res[j]
                TreeNode* LastRight = res[j]->right;
                TreeNode* treehead = new TreeNode(-1);
                treehead->right = copy;
                while(LastRight != NULL){
                    copy = copytree(res[j]);
                    treehead->right = copy;
                    while(copy->right->val != LastRight->val)  // find the place last time
                        copy = copy->right;
                    LastRight = LastRight->right;
                    
                    newNode = new TreeNode(i);  //reload newNode
                    newNode->left = copy->right;
                    copy->right = newNode;
                    
                    tmp.push_back(treehead->right);
                }
                
                copy = copytree(res[j]);
                treehead->right = copy;
                while(copy->right != NULL)
                    copy = copy->right;
                newNode = new TreeNode(i);////update
                copy->right = newNode;
                tmp.push_back(treehead->right);
            }
            res = tmp;
        }
        return res;
    }
    
    TreeNode* copytree(TreeNode* root){
        if(root == nullptr) return nullptr;
        TreeNode* newroot = new TreeNode(0);
        newroot->val = root->val;
        newroot->left = copytree(root->left);
        newroot->right = copytree(root->right);
        return newroot;
    }
};
