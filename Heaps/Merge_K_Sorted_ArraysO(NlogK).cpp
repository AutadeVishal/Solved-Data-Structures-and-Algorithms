class Solution
{
    public:
    //Function to merge k sorted arrays.
    class node{
        public:
        int data,row,col;
        node(int val,int i,int j){
          data=val;
         row=i;
         col=j;  
        }
         
    };
  struct compare {
        bool operator()(node* a, node* b) {
            return a->data > b->data; 
        }
    };
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<node *,vector<node *>,compare>q;
        for(int i=0;i<K;i++){
            node * temp=new node(arr[i][0],i,0);
            q.push(temp);
        }
        vector<int> v;
        while(!q.empty()){
            v.push_back(q.top()->data);
            if(q.top()->col<arr[0].size()-1){
                node * temp=new node(arr[q.top()->row][q.top()->col+1],q.top()->row,q.top()->col+1);
                q.pop();
                q.push(temp);
                
            }
            else{
                
                  q.pop();
            }
          
            
        }
        return v;
        
    }
};
