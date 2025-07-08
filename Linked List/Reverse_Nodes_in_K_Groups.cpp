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
    ListNode * solve(ListNode * head,int k){
        if(head==nullptr)return nullptr;
        int count=k;
         ListNode * prev=nullptr;
         ListNode * ahead=nullptr;
         ListNode * curr=head;
        while(count && curr!=nullptr){
            ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
            count--;
        }
        if(count){
            curr=prev;
            prev=nullptr;
            ahead=curr->next;
        
        while((k-count) && curr!=nullptr){
           if(curr) ahead=curr->next;
           if(curr) curr->next=prev;
            prev=curr;
            curr=ahead;

        }
        return prev;
        }
        head->next=solve(curr,k);

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return solve(head,k);
    }
};
