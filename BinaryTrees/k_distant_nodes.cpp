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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        TreeNode* ptr=root;
        vector<int>arr;
        TreeNode* prev=target;
        arr=findDistanceK(target,arr,0,k);
        for(int i=1;i<=k;i++){
            TreeNode* temp=prev;
            prev=findPrev(root,prev);
           
            if(prev){
                if(prev->left==temp){
                    findDistanceK(prev->right,arr,i+1,k);
                }
                else{
                    findDistanceK(prev->left,arr,i+1,k);
                }
            }
        }
        if(prev && k!=0){
            arr.push_back(prev->val);
        }
        return arr;
 
    }
    vector<int> findDistanceK(TreeNode*ptr,vector<int> &arr,int d,int k ){
        if(d==k){
            if(ptr==nullptr){
                return arr;
            }
            else{
                arr.push_back(ptr->val);
                return arr;
            }
        }
        else if(ptr==nullptr){
            return arr;
        }
        else{
            findDistanceK(ptr->left,arr,d+1,k);
            findDistanceK(ptr->right,arr,d+1,k);
        }
        return arr;
    }
    TreeNode* findPrev(TreeNode* root,TreeNode* target){
        if(root==nullptr || target==nullptr){
            return nullptr;
        }
        else if(root==target){
            return nullptr;
        }
        else if(root->right==target ||root->left==target){
            return root;
        }
 
        
        else{
            TreeNode* r=findPrev(root->right,target);
            TreeNode* l=findPrev(root->left,target);
            if(l!=nullptr){
                return l;
            }
            else{
                return r;
            }
        }
    }
};