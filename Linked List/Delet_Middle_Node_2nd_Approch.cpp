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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            delete head;
          return nullptr;
        }
        else{
        ListNode * slow=head;
        ListNode * prev=nullptr;
        ListNode * fast=head->next;
        while(fast!=nullptr){
            fast=fast->next;
            if(fast!=nullptr){
            fast=fast->next;
            }
            prev=slow;
            slow=slow->next;
            
        }
        prev->next=slow->next;
        slow->next=nullptr;
        delete slow;
        return head;
    }
    }
};
