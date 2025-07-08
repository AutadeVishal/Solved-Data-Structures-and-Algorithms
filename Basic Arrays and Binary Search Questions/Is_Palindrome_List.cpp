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
ListNode * rev(ListNode * &head){
    ListNode *prev=nullptr;
    ListNode * curr=head;
    ListNode * ahead=head->next;
    while(curr!=nullptr){
       ahead= curr->next;
       curr->next=prev;
       prev=curr;
       curr=ahead; 
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr){
            return true;
        }
        ListNode * slow=head;
        ListNode * fast=head;
        while(fast->next!=nullptr){
           
fast=fast->next;
 if(fast->next!=nullptr){
                fast=fast->next;
            }
slow=slow->next;
        }

        slow=rev(slow);
        fast=head;
        while(slow!=nullptr){
            if(fast->val!=slow->val)return false;
            fast=fast->next;
            slow=slow->next;
        }
        return true;
    }
};
