//
//  662.cpp
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
//#include<algorithm.h>
class Solution {
    vector<int> A;  // store all place index
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        A.push_back(1); // the root index
        AVal(root, 1);
        sort(A.begin(),A.end());
        int Max=0;
        int level = (int)(log(A.back())/log(2)); // the root is level 0
        // nums in every level is between [2^level,2^(level+1)-1)
        
        while(!A.empty()){
            int lr = A.back(); A.pop_back();
            int tmp = lr;
            while((int)(log(A.back())/log(2)) == level){
                tmp = A.back();
                A.pop_back();
            }
            Max = max(Max,lr-tmp);
            level--;
        }
        return Max+1; // becasue set the first level as 0
    }
    // label the position index
    void AVal(TreeNode* root,int n){
        if(root->left){
            A.push_back(2*n);
            AVal(root->left,2*n);
        }
        if(root->right){
            A.push_back(2*n+1);
            AVal(root->right,2*n+1);
        }
    }
};
