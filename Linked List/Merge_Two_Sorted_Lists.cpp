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
ListNode* solve(ListNode* &list1, ListNode* list2) {
    ListNode* ans = list1;
    ListNode* prev1 = list1;
    ListNode* curr1 = list1->next;
    ListNode* curr2 = list2;

    while (curr1 != nullptr && curr2 != nullptr) {
        if (curr2->val >= prev1->val && curr2->val <= curr1->val) {
            prev1->next = curr2;
            ListNode* temp = curr2->next;
            curr2->next = curr1;
            prev1 = curr2;
            curr2 = temp;
        } else {
            prev1 = curr1;
            curr1 = curr1->next;
        }
    }

    if (curr2 != nullptr) {
        prev1->next = curr2;
    }

    return ans;
}

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==nullptr){
            return list2;
        }
        if(list2==nullptr){
            return list1;
        }
        if(list1->val<=list2->val){
            return solve(list1,list2);
        }
        else{
            return solve(list2,list1);
        }
    }
};
