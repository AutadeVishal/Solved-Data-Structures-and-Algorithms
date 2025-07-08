//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int first_element(int arr[],int n,int x){
    int low=0;
    int high=n-1;
    int mid;
    int l=INT_MAX;
    while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]==x && l>mid){
            l=mid;
            high=mid;
        }
        else if(arr[mid]<x){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(l!=INT_MAX){
        return l;
    }
    else{
    return -1;
    }
}
int last_element(int arr[],int n,int x){
    int low=0;
    int high=n-1;
    int mid;
    int h=INT_MIN;
    while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]==x && h<mid){
            h=mid;
            low=mid+1;
        }
        else if(arr[mid]<x){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(h!=INT_MIN){
        return h;
    }
    return -1;
}
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        vector<int>v;
        v.push_back(first_element(arr,n,x));
        v.push_back(last_element(arr,n,x));
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends