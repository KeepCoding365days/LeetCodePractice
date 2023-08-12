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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int>a;
        vector<vector<int>>ret;
        if(root){
            levelOrderR(root,ret,1);
        }
        return ret;
    }
    void levelOrderR(TreeNode* root,vector<vector<int>>& ret,int level){
        if (root==nullptr){
            return;
        }
        else{
           if(level>ret.size()){
                vector<int>a;
               ret.push_back(a);
           }
           ret[level-1].push_back(root->val);
           levelOrderR(root->left,ret,level+1);
           levelOrderR(root->right,ret,level+1);
          
        }
    }
};