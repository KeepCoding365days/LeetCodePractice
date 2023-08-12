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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ptr_new=nullptr;
        ListNode* ret_ptr=nullptr;
        ListNode* ptr;
        int count_0=0;
        int sum=0;
        for(ptr=head->next;ptr!=nullptr;ptr=ptr->next){
            if(ptr->val==0){
                count_0++;
                if(count_0==1){
                ptr_new=new ListNode(sum,nullptr);
                ret_ptr=ptr_new;
                }
                else{
                    ptr_new->next=new ListNode(sum,nullptr);
                    ptr_new=ptr_new->next;
                }
                sum=0;
            }
            else{
                sum+=ptr->val;
            }
        }
        return ret_ptr;
    }
};