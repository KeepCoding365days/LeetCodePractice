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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> arr;
        if(root!=nullptr){
            queue<TreeNode*> q;
            q.push(root);
            arr.push_back(q.front()->val);
            while(!q.empty()){
                int size=q.size();
                for(int i=0;i<size;i++){
                    TreeNode* ptr=q.front();
                    q.pop();
                    if(ptr->left!=nullptr){
                        q.push(ptr->left);
                    }
                    if(ptr->right!=nullptr){
                        q.push(ptr->right);
                    }
                }
                if(!q.empty()){
                    arr.push_back(q.back()->val);
                }
            }
        }
        return arr;
    }
};
