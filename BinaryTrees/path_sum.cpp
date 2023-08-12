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
        pathSumR(root,targetSum,ret,a,0);
        return ret;
    }
    vector<vector<int>> pathSumR(TreeNode*root,int targetSum,vector<vector<int>>&ret,vector<int> path,int sumpath){
        if(root==nullptr){
            return ret;
        }
        else {
            sumpath=sumpath+root->val;
            path.push_back(root->val);
            if(sumpath==targetSum && isleaf(root)){
                ret.push_back(path);
                return ret;
            }
            else{
                pathSumR(root->left,targetSum,ret,path,sumpath);
                pathSumR(root->right,targetSum,ret,path,sumpath);
            }
        }
        
        return ret;
    }
    bool isleaf(TreeNode* ptr){
        return (ptr->left==nullptr && ptr->right==nullptr);
    }
};