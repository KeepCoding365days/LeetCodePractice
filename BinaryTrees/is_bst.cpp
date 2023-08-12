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
    bool isValidBST(TreeNode* root) {
        bool check=true;
        if(root){
            check=isValidBSTR(root,root,check);
        }
        else{
            check=false;
        }
        return check;
    }
    bool isValidBSTR(TreeNode* root,TreeNode* ptr,bool & check){
        if(ptr && check){
            if(ptr->left){
                if(ptr->left->val>=ptr->val){
                    check= false;
                    return check;
                }
                
            }
            if(ptr->right){
                if(ptr->right->val<=ptr->val){
                    check=false;
                    return check;
                }
            }
            TreeNode* temp=root;
            while(temp!=ptr && temp!=nullptr){
                if(ptr->val<temp->val){
                    temp=temp->left;
                }
                else if(ptr->val>temp->val){
                    temp=temp->right;
                }
                else{
                    temp=nullptr;//no duplicates
                }
            }
            if(temp==nullptr){
                check=false;
                return check;
            }
            isValidBSTR(root,ptr->left,check);
            isValidBSTR(root,ptr->right,check);
        }
        return check;
    }
    
};