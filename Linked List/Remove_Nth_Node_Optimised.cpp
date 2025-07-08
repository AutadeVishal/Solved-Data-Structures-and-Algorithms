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
        ListNode * first=head;
        ListNode * second=head;
        for(int i=0;i<n;i++)second=second->next;
        if(second==nullptr)return first->next;
        while(second->next!=nullptr){
            first=first->next;
            second=second->next;
        }
        first->next=first->next->next;
        return head;
    }
};
