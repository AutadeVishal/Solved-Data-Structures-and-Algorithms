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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode * prev=NULL;
        ListNode * curr=head;
       while(curr){
        if(curr==nullptr && head==nullptr)return nullptr;
        if( curr && curr->next && curr->next->val==curr->val){
            while(curr && curr->next && curr->val==curr->next->val){
                curr=curr->next;
            }
            
           if(prev){ 
            prev->next=curr->next;
            }
           else{
            head=curr->next;
           }
        }
        else{
            prev=curr;
        }

            curr=curr->next;
       }
        return head;
    }
};
