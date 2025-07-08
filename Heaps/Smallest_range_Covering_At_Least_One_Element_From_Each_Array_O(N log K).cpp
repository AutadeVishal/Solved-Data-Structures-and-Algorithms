class Solution {
public:
class node{
    public:
    int row,col,data;
    node(int val,int i,int j){
        data=val;
        row=i;
        col=j;
    }
};
class comparesmall {
     public:   bool operator()(node* a, node* b) {
            return a->data > b->data; 
        }
    };  
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<vector<int>>ranges;
        priority_queue<node *,vector<node *>,comparesmall>smallest;
vector<int>ans;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            node * temp=new node(nums[i][0],i,0);
            smallest.push(temp);
            maxi=max(maxi,nums[i][0]);
        }
        while(!smallest.empty()){
            int min=smallest.top()->data;
            int row=smallest.top()->row;
            int col=smallest.top()->col;
            
             node * temp=smallest.top();
            smallest.pop();
            delete temp;
             if(ans.empty() || (ans[1]-ans[0]>maxi-min || (ans[1]-ans[0]==maxi-min && ans[0]>min))){
                ans={min,maxi};
             }
             if(col<nums[row].size()-1) {
                     temp=new node(nums[row][col+1],row,col+1);
                    smallest.push(temp);
                  maxi=max(maxi,nums[row][col+1]);
             }
             else break;
           
           
           
        }
        return ans;
    }
};
