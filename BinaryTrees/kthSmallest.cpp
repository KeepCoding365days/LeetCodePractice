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
    int kthSmallest(TreeNode* root, int k) {
        vector <int> arr;
        pre_order(root,arr);
        return arr.at(k-1);
        
    }
    void pre_order(TreeNode* root,vector <int> &arr){
        if(root==nullptr){
            return;
        }
        else if(root->left!=nullptr){
            pre_order(root->left,arr);
            arr.push_back(root->val);
            pre_order(root->right,arr);
        }
        else{
            arr.push_back(root->val);
            pre_order(root->right,arr);
        }
    }
};