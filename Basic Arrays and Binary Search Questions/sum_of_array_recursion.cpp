#include<iostream>
using namespace std;
int sum(int arr[],int size){
    if(*arr==arr[size-1]){
        return *arr;
    }
    int val=arr[0]+sum(arr+1,size-1);
    return val;
}
int main(){
int a[5]={6,4,5,6,78};
int size=5;
cout<<sum(a,size);




    return 0;
}