//
//  109.cpp
//
//  Created by Ava on 2018/4/22.
//  Copyright © 2018年 Ava. All rights reserved.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        return BuildBST(head,NULL);
    }
    
    TreeNode* BuildBST(ListNode* head,ListNode* tail){
        if(head==tail)    // the last node
            return NULL;
        else if(head->next == tail){
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        // there are more than two nodes
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != tail && fast->next != tail){
            slow = slow->next;     // find the mid
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        root->left = BuildBST(head,slow);
        root->right = BuildBST(slow->next,tail);
        return root;
        
    }
};
