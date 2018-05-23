/*questions:
Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
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
// ver1
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        if(root->left || root->right) 
            swap(root);
        if(root->left) invertTree(root->left);
        if(root->right)invertTree(root->right);
        return root;
    }
    void swap(TreeNode* root){
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }
};

//ver2
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            swap(root->left,root->right);
            invertTree(root->right);
            invertTree(root->left);
        }
        return root;
    }
};
