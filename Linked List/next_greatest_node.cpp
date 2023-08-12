/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        ListNode*ptr=head;

        while(ptr->next!=nullptr){
            int max=ptr->val;
            bool found=false;
            for(ListNode* i=ptr->next;i!=nullptr &&!found;i=i->next){
                if (i->val>max){
                    max=i->val;
                    found=true;
                }
            }
            if(max>ptr->val){
                arr.push_back(max);
            }
            else{
                arr.push_back(0);
            }
            ptr=ptr->next;
        }
        arr.push_back(0);
        return arr;
    }
};