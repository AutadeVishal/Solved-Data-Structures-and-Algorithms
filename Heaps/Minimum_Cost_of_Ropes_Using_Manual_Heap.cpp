class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    void heapify(vector<int>&arr,int position,int size){
        int smallest=position;
        int left=smallest*2+1;
        int right=smallest*2+2;
        if(left<size && arr[left]<arr[smallest]) smallest=left;
        if(right <size && arr[right]<arr[smallest]) smallest=right;
        if(smallest!=position){
            swap(arr[smallest],arr[position]);
            heapify(arr,smallest,size);
        }
    }
    int minCost(vector<int>& arr) {
        int sum=0;
        int size=arr.size();
        for(int i=(arr.size()-1)/2;i>=0;i--){
            heapify(arr,i,size);
        }
        while(size>1){
           int a=arr[0];
           swap(arr[0],arr[size-1]);
           size--;
           heapify(arr,0,size);
           int b =arr[0];
           swap(arr[0],arr[size-1]);
           size--;
           heapify(arr,0,size);
           arr[size++]=a+b;
           sum+=a+b;
           
            
        }
        return sum;
    }
};
