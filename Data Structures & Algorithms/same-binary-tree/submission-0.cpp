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
    void preOrder(TreeNode* root,vector<string>&res){
        if(root == NULL){
            res.push_back("NULL");
            return;
        }
        res.push_back(to_string(root->val));
        preOrder(root->left,res);
        preOrder(root->right,res);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<string> res1;
        vector<string> res2;

        preOrder(p,res1);
        preOrder(q,res2);

        return res1 == res2;
    }
};
