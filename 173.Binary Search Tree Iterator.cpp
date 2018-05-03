//
//  173.cpp
//
//  Created by Ava on 2018/5/3.
//  Copyright © 2018年 Ava. All rights reserved.
//

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/////remember this function may be used for many times, not only one time, so should keep the BST correct !!!
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(s.empty()) return false;
        return true;
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* Cur = s.top();
        int m = Cur->val;
        s.pop();
        Cur = Cur->right;
        while(Cur){
            s.push(Cur);
            Cur = Cur->left;
        }
        return m;
    }
private:
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
