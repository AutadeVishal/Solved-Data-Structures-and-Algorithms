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
    void deleteNode(ListNode* node) {
        ListNode * temp=node;
        node=node->next;
        while(node->next){
            temp->val=node->val;
            temp=temp->next;
            node=node->next;
        }
        temp->val=node->val;
        temp->next=nullptr;
    }
};
