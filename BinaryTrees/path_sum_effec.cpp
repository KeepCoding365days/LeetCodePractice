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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> a;
        vector<vector<int>> ret;
        pathSumR(root,targetSum,ret,a);
        return ret;
    }
    void pathSumR(TreeNode*root,int targetSum,vector<vector<int>>&ret,vector<int>& path){
        if(root==nullptr){
            return;
        }
       
        path.push_back(root->val);
        if(root->val==targetSum && isleaf(root)){
            ret.push_back(path);
        }
        pathSumR(root->left,targetSum-root->val,ret,path);
        pathSumR(root->right,targetSum-root->val,ret,path); 
        path.pop_back();
    }
    bool isleaf(TreeNode* ptr){
        return (ptr->left==nullptr && ptr->right==nullptr);
    }
};