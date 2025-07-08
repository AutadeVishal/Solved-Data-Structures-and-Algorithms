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
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head || !head->next)return head;
        ListNode * first=nullptr;
        ListNode* second=nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev1=nullptr;
        ListNode* prev2=nullptr;
        for(int i=0;i<k-1;i++){
            prev1=fast;
            fast=fast->next;
            
        }
        first=fast;
        while(fast->next){
            prev2=slow;
            fast=fast->next;
            slow=slow->next;
        }
        second=slow;
       
        if(second==first){
            return head;
        }
        if (prev1) prev1->next = second; 
        if (prev2) prev2->next = first; 
        ListNode* temp = second->next;
        second->next = first->next;
        first->next = temp;
        if (first == head) {
            head = second;
        } else if (second == head) {
            head = first;
        }

        return head;

    }
};
