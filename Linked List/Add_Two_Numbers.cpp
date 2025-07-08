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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* nnode = new ListNode();
        ListNode* temp = nnode;
        int carry = 0;
        while (curr1 && curr2) {
            int num = (curr1->val + curr2->val + carry) % 10;
            carry = (curr1->val + curr2->val + carry) / 10;
            temp->next = new ListNode(num);
            temp = temp->next;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while (curr1 != nullptr) {
            int num = (curr1->val + carry) % 10;
            carry = (curr1->val + carry) / 10;
            temp->next = new ListNode(num);
            temp = temp->next;
            curr1 = curr1->next;
        }
        while (curr2 != nullptr) {
            int num = (curr2->val + carry) % 10;
            carry = (curr2->val + carry) / 10;
            temp->next = new ListNode(num);
            temp = temp->next;
            curr2 = curr2->next;
        }
        if (carry != 0) {
            temp->next = new ListNode(carry);
        }

        return nnode->next;
    }
};
