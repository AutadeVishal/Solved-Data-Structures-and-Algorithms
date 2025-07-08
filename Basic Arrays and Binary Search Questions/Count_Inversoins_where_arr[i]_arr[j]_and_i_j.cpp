//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // I am using merge sort to divide and then using merge to follow the condition
    void find(vector<long long >&arr,long long low,long long high,long long mid,long long &count){
        long long n1=mid-low+1;
        long long n2=high-mid;
        long long arr1[n1];
        long long arr2[n2];
        for(long long i=0;i<n1;i++){
            arr1[i]=arr[low+i];
        }
        for(long long i=0;i<n2;i++){
            arr2[i]=arr[i+mid+1];
        }
        long long i=0,j=0,p=low;
        while(i<n1 && j<n2){
            if(arr1[i]<=arr2[j]){
                arr[p++]=arr1[i++];
            }
            else{
                count+=n1-i;
                arr[p++]=arr2[j++];
            }
        }
        while(i<n1){
            arr[p++]=arr1[i++];
        }
        while(j<n2){
            arr[p++]=arr2[j++];
        }    
        
    }
    void solve(vector<long long>&arr,long long  low,long long high,long long &count){
        if(low>=high){
            return;
        }
        long long  mid=low+(high-low)/2;
        solve(arr,low,mid,count);
        solve(arr,mid+1,high,count);
        find(arr,low,high,mid,count);
    }
    long long int inversionCount(vector<long long> &arr) {
       long long count=0;
       solve(arr,0,arr.size()-1,count);
       return count;
    }
};

//{ Driver Code Starts.

int main() {

    long long T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<long long> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        long long num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
    }

    return 0;
}

// } Driver Code Ends
