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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp1=head;
        ListNode * temp2=nullptr;
        ListNode * curr=head;
        ListNode * prev=nullptr;
        ListNode * ahead=nullptr;
        ListNode * check=head;
       
        int n=0;
        while(check!=nullptr){
            check=check->next;
            n++;
        }
        int times=n/k;
         if(k==1 || k>n ){
            return head;
        }
        int count=0;
        while(curr!=nullptr && times!=0){
             count++;
            ahead=curr->next;
            curr->next=prev;
            prev=curr;
            curr=ahead;
            if(count==k){
              times--;
                if(temp2!=nullptr){
                    temp1->next=prev;
                    temp1=temp2;
                    temp2=curr;

                }
                  else{
                    temp2=curr;
                    head=prev;
                }
                count=0;
                prev=nullptr;
            }
           
        }
       if (temp1 != nullptr) {
            temp1->next = temp2;
        }
        return head;
    }
};
