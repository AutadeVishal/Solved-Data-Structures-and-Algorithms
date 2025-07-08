class Solution{
    public:
    void heapify(vector<int> & ans,int position){
        int parent=(position-1)/2;
        while(position>=0  && ans[parent]<ans[position]){
            swap(ans[parent],ans[position]);
            position=parent;
              parent=(position-1)/2;
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    vector<int>ans;
    int i=0;
    int j=0;
    int last=0;
    while(i<n || j<m){
        if(i<n && (j>=m ||  a[i]>b[j])){
            ans.push_back(a[i++]);
            heapify(ans,last++);
        }
        else{
            ans.push_back(b[j++]);
            heapify(ans,last++);
        }
    }
    
    return ans;
    }
};
