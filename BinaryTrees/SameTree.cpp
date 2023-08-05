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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool check=true;
        isSameTreeR(p,q,check);
        return check;
    }
    void isSameTreeR(TreeNode* p_root,TreeNode* q_root,bool & check){
        if(p_root && q_root && check){
            if(p_root->val==q_root->val){
                isSameTreeR(p_root->left,q_root->left,check);
                isSameTreeR(p_root->right,q_root->right,check);
            }
            else{
                check=false;
                return;
            }
        }
        else if(p_root !=q_root){
            check=false;
            return;
        }
    }
};