int pivot(vector<int>&arr,int s,int e){
    int mid=s+(e-s)/2;
    if(s>e){
        return -1;
    }
    if(arr[0]>arr[1]){
        return 0;
    }
    
    if (mid < e && arr[mid] > arr[mid + 1]) return mid;
    if (mid > s && arr[mid] < arr[mid - 1]) return mid - 1;

    if(arr[mid]>=arr[0]){
return pivot(arr,mid+1,e);
    }
    else{
        return pivot(arr,s,mid);
    }
}
int binary(vector<int>&arr,int s,int e,int k){
    int mid=s+(e-s)/2;
    if(s>e){
        return -1;
    }
    if(arr[mid]==k){
        return mid;
    }
    else if(arr[mid]>k){
        return binary(arr,s,mid-1,k);
    }
    else{
        return binary(arr,mid+1,e,k);
    }
}
int search(vector<int>& arr, int n, int k){
    int p=pivot(arr,0,n-1);
if(p==-1){
    return binary(arr,0,n-1,k);
}
if(arr[p]==k)return p;
    if(k>arr[0]){
return binary(arr,0,p,k);
    } else {
return binary(arr,p + 1, n - 1, k);
    }

    

}
