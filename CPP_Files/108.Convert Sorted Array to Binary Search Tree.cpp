//
//  108.cpp

//
//  Created by Ava on 2018/4/17.
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return NULL;
        
        int m = n/2;
        TreeNode* root = new TreeNode(nums[m]); // define the root
        
        vector<int> LeftP;
        for(int i=0;i<m;i++) LeftP.push_back(nums[i]);
        vector<int> RightP;
        for(int i=m+1;i<n;i++) RightP.push_back(nums[i]);
        
        root->left = sortedArrayToBST(LeftP);
        root->right = sortedArrayToBST(RightP);
        return root;
    }
};
