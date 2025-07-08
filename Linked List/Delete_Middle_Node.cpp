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
        if(head==nullptr || head->next==nullptr)
        {
            delete head;
            return nullptr;
        }
          ListNode* curr=head;
        int ct=0;
        while(curr!=nullptr){
            ct++;
            curr=curr->next;
        }
        curr=head;
        ListNode * prev=nullptr;
        for(int i=0;i<(ct/2);i++){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        curr->next=nullptr;
        delete curr;
        return head;
    }
};
