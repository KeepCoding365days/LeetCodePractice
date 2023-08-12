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
        TreeNode* ptr=root;
        if(root!=nullptr){
            if(root!= p && root!=q){
                bool temp=false;
                lowestCommonAncestorR(root,ptr,p,q,temp);
            }
        }
        return ptr;
    }
    void lowestCommonAncestorR(TreeNode* root,TreeNode* &ptr,TreeNode* p,TreeNode* q,bool &found){
        if(found){
            return;
        }
        if(root->left->val==p->val){
            cout<<'a';
            found=true;
            if(root->right->val==q->val){
                
                ptr=root;
            }
            else{
                ptr=root->left;
            }
            return;
        }
        else if(root->left->val==q->val){
            found=true;
            if(root->left->val==p->val){
                ptr=root;
            }
            else{
                ptr=root->left;
            }
            return;
        }
        else{
            lowestCommonAncestorR(root->left,ptr,p,q,found);
            lowestCommonAncestorR(root->right,ptr,p,q,found);
        }
    }
};