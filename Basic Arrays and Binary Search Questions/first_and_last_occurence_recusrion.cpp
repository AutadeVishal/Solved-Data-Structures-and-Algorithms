int first(vector<int>&arr,int s,int e,int k){
int mid=s+(e-s)/2;
if(s>e){
  return -1;
}
if((arr[mid]==k && mid==0)||(arr[mid]==k && arr[mid-1]!=k)){
  return mid;
}
if(arr[mid]==k){
   return first(arr,s,mid-1,k);
}
else if(arr[mid]<k){
  return first(arr,mid+1,e,k);
} else {
  return first(arr, s, mid - 1, k);
}
}
int last(vector<int>&arr,int s,int e,int k){
int mid=s+(e-s)/2;
if(s>e){
  return -1;
}
if((arr[mid]==k && mid==arr.size()-1)||(arr[mid]==k && arr[mid+1]!=k)){
  return mid;
}
if(arr[mid]==k){
   return last(arr,mid+1,e,k);
}
else if(arr[mid]<k){
  return last(arr,mid+1,e,k);
} else {
  return last(arr, s, mid - 1, k);
}
}
pair<int, int> firstAndLastPosition(vector<int> & arr, int n, int k) {
  return make_pair(first(arr, 0, n - 1, k), last(arr, 0, n - 1, k));
}