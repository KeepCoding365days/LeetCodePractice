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
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        pathSumIII(root,targetSum,count);
        return count;
        
    }
    void pathSumIII(TreeNode* root,int targetSum,int &count){
        if (root==nullptr){
            return;
        }
        else{
            pathSumR(root,targetSum,0,count);
            pathSumIII(root->left,targetSum,count);
            pathSumIII(root->right,targetSum,count);
        }
    }
    void pathSumR(TreeNode*root,int targetSum,double sumpath,int &count){
        if(root==nullptr){
            return;
        }
        else {
            sumpath=sumpath+root->val;
            if(sumpath==targetSum ){
                count=count+1;
            }
            pathSumR(root->left,targetSum,sumpath,count);
            pathSumR(root->right,targetSum,sumpath,count);
        }
    }
};