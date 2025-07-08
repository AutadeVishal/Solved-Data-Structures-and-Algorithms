vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    for(int i=0;i<arr.size()-1;i++){
        bool k=false;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[i] ){
                arr[i]=arr[j];
                k=true;
                break;
            }
        }
        if(!k){
            arr[i]=-1;
        }
    }
    arr[arr.size()-1]=-1;
    return arr;
}
