/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root!=nullptr){
            if(p->val<q->val){
                lowestCommonAncestorR(root,p,q);
            }
            else{
                lowestCommonAncestorR(root,q,p);
            }
        }

        return root;
    }
    void lowestCommonAncestorR(TreeNode* &root,TreeNode* p,TreeNode*q){
        if(root->val==p->val){
             return;
        }
        else if(root->val==q->val){
            return;
        }
        else if(root->val>q->val){
            root=root->left;
            lowestCommonAncestorR(root,p,q);
        }
        else if(root->val<p->val){
            root=root->right;
            lowestCommonAncestorR(root,p,q);
        }
        else{
            return;
        } 
    }
};
