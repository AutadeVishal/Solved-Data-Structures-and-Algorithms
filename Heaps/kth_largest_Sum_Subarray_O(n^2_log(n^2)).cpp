class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
      vector<int>v;
      for(int i=0;i<arr.size();i++){
          int sum=0;
          for(int j=i;j<arr.size();j++){
              sum+=arr[j];
              v.push_back(sum);
          }
      }
      sort(v.begin(),v.end());
      return v[v.size()-k];
    }
};
