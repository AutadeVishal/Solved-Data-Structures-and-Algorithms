/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* sortList(Node *head){
   Node * temp=head;
   int a=0,b=0,c=0;
   while(temp!=nullptr){
       if(temp->data==0)a++;
       else if(temp->data==1)b++;
       else c++;
       temp=temp->next;
   }
    temp=head;
    while (temp!=nullptr) {
       if (a > 0)
         temp->data = 0, a--;
       else if (b > 0)
         temp->data = 1, b--;
       else
         temp->data = 2, c--;
       temp = temp->next;
    }
    return head;
}
