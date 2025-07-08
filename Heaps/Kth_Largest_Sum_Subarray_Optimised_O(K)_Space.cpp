class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
    priority_queue<int, vector<int>, greater<int> >p;
      for(int i=0;i<arr.size();i++){
          int sum=0;
          for(int j=i;j<arr.size();j++){
              sum+=arr[j];
              if(p.size()<k){
                  p.push(sum);
              }
              else{
                  if(p.top()<sum){
                      p.pop();
                      p.push(sum);
                  }
              }
          }
      }
    return p.top();
    }
};
