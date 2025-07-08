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
int returnsum(ListNode * head1,ListNode * head2){
    int sum=0,m=INT_MIN;
    while(head2!=nullptr){
        sum=head1->val+head2->val;
        m=(max(m,sum));
        head1=head1->next;
        head2=head2->next;
    }
    return m;
}
ListNode * reverselist(ListNode * head){
    ListNode * curr=head;
    ListNode * prev=nullptr;
    ListNode * ahead=nullptr;
    while(curr!=nullptr){
        ahead=curr->next;
        curr->next=prev;
        prev=curr;
        curr=ahead;
    }
    return prev;
}
ListNode * findmid(ListNode * head){
ListNode * slow=head;
ListNode * fast=head;
while(fast!=nullptr){
    if(fast->next!=nullptr){
        fast=fast->next;
    }
    fast=fast->next;
    slow=slow->next;
}
return slow;
}
    int pairSum(ListNode* head) {
        ListNode * head2=findmid(head);
        head2=reverselist(head2);
        return returnsum(head,head2);
    }
};
