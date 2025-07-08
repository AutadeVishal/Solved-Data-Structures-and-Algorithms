/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
      if(head)  if(head->next==head)return true;
        unordered_set<ListNode *>a;
        ListNode * temp=head;
        while(temp!=nullptr){
             if(a.find(temp)!=a.end()){
                return true;
            }
            a.insert(temp);
           
            temp=temp->next;
        }
        return false;
    }
};
