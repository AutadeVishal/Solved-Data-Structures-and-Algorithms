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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr)return nullptr;
        int c=0;
    ListNode * temp=head;
    while(temp!=nullptr){
        c++;
        temp=temp->next;
    }
    temp=head;
    if(c==n){
        return head->next;
    }
    int a=c-n;
    
    while(a!=1){
temp=temp->next;
a--;
    }
    ListNode * temp2=temp->next;
    temp->next=temp2->next;
    delete temp2;
    return head;
    }
};
