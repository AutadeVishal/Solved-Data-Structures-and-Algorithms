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
struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; 
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        priority_queue<ListNode * ,vector<ListNode *>,compare>p;
        for(auto i:lists){
          if(i!=nullptr) p.push(i);
        }
        ListNode * root=nullptr;
       ListNode *curr=nullptr;
       ListNode * prev=nullptr;
       while(!p.empty()){
       curr=p.top();
       p.pop();
       if(!root){
        root=curr;
        
       }
        else{
            prev->next=curr;
        }       
       if(curr->next) p.push(curr->next);
        prev=curr;
       }
       return root;
    
    }
};
