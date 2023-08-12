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
    int sumNumbers(TreeNode* root) {
        int path_sum=0;
        int sum=0;
        sumNumbersR(root,path_sum,sum);
        return sum;
    }
    int sumNumbersR(TreeNode* root,int  path_sum,int & sum){
        if(root==nullptr){
            return sum;
        }
        else if(isleaf(root)){
            path_sum=path_sum*10+root->val;
            sum=sum+path_sum;
            return sum;
        }
        else{
            path_sum=path_sum*10+root->val;
            sumNumbersR(root->left,path_sum,sum);
            sumNumbersR(root->right,path_sum,sum);
        }
        return sum;
    }
    bool isleaf(TreeNode*ptr){
        return (ptr->left==nullptr && ptr->right==nullptr);
    }
};