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
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr)return nullptr;
        if(head->next==nullptr)return head;
        ListNode * temp1=head;
        ListNode * temp2=nullptr;
        ListNode * prev=nullptr;
        ListNode * curr=head;
        ListNode * ahead=nullptr;
        ListNode * result=nullptr;
        int count=0;
        while(curr!=nullptr){
           
            if(count==2){
                count=0;
                if(temp2==nullptr){
                    temp2=curr;
                    result=prev;
                    prev=nullptr;
                }
                else{
                    temp1->next=prev;
                    temp1=temp2;
                    temp2=curr;
                    prev=nullptr;
                }
            }
            ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
             count++;
        }
        if(count==2 && temp2==nullptr){
            return prev;
        }
         temp1->next=prev;
        return result;

    }
};
