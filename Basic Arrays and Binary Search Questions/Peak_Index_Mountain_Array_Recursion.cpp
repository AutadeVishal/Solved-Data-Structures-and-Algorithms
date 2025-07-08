class Solution {
public:
int peak(vector<int>&arr,int s,int e){
    int mid=s+(e-s)/2;
    if(s>e){
        return -1;
    }
    if(arr[0]>arr[1]){
        return 0;
    }

       
         if((mid!=0 && arr[mid]>arr[mid-1] ) && ( mid<arr.size()-1 && arr[mid]>arr[mid+1] )){
            return mid;
         }
         if(arr[mid]>arr[mid-1] && mid>0){
            return peak(arr,mid+1,e);
         }
         else{
            return peak(arr,s,mid);
         }
    

    
}
    int peakIndexInMountainArray(vector<int>& arr) {
        return peak(arr,0,arr.size()-1);
    }
};
