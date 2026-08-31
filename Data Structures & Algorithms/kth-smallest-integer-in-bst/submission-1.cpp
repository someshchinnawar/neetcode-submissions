/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    //use inorder you can get the traversal in sorted order as this is a BST 
    //and whenever you get the element increase the count
    //and when cnt == k return that element
    int count = 0;
    int ans = -1;
    void inOrder(TreeNode* root, int k){
        if(root == NULL){
            return;
        }
        inOrder(root->left,k);
        count++;
        if(count == k){
            ans = root->val;
            return;
        }
        inOrder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root,k);
        return ans;
    }   
};
