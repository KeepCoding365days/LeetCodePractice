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
    bool isLeaf(TreeNode* ptr){
        bool check=false;
        if(ptr->left==nullptr && ptr->right==nullptr){
            return true;
        }
        return check;
    }
    bool isSymmetric(TreeNode* root) {
        bool check=true;
        if(root){
            if(root->left && root->right){
            if(root->left->val==root->right->val){
                check=isSymmetricR(root->left,root->right,check);
            }
            else{
                return false;
            }
            }
            else if(root->left || root->right){
                check=false;
            }
        }
        return check;
    }
    bool isSymmetricR(TreeNode* ptr_left,TreeNode* ptr_right,bool &check){
        if(ptr_left && ptr_right){
        if(!check){
            return check;
        }
        else if(ptr_left->val==ptr_right->val){
            check=true;
            if(isLeaf(ptr_left) && isLeaf(ptr_right)){
            return check;
        }
        else if(isLeaf(ptr_left)|| isLeaf(ptr_right)){
            check=false;
            return check;
        }
            isSymmetricR(ptr_left->left,ptr_right->right,check);
            isSymmetricR(ptr_left->right,ptr_right->left,check); 
        }
        else{
            check=false;
            return check;
        }
        }
        else if(ptr_left || ptr_right){
            check=false;
            return check;
        }
        return check;
    }
};