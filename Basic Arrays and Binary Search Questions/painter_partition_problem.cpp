// User function template in C++
bool ifpossible(int arr[],int n,int m,int mid){
    int sum=0;
    int c=1;
    for(int i=0;i<n;i++){
    if(arr[i]>mid){
        return false;
    }
        if(sum+arr[i]>mid){
            c++;
            sum=arr[i];
             if(c>m ){
                return false;
            }
        }
        else{
           
        sum+=arr[i];
            
        }
    }
    return true;
}
class Solution {
  public:
    // Function to find minimum number of pages.
    long long findPages(int n, int arr[], int m) {
        if(n<m){
            return -1;
        }
        int ans=-1;
        int mid;
        int low=0;
        int high=0;
        for(int i=0;i<n;i++){
            high+=arr[i];
        }
        while(low<=high){
         mid=low+(high-low)/2;
         if(ifpossible(arr,n,m,mid)==true){
             ans=mid;
             high=mid-1;
         }
         else{
             low=mid+1;
         }
        }
        return ans;
    }
};