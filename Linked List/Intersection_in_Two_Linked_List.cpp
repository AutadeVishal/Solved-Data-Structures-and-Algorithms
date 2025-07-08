class Solution {
  public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        unordered_map<Node * ,bool>m;
        Node * temp=head1;
        while(temp){
                m[temp]=true;
                temp=temp->next;
        }
        temp=head2;
        while(temp){
            if(m[temp]){
                return temp->data;
            }
            else{
                temp=temp->next;
            }
        }
        return -1;
    }
};
