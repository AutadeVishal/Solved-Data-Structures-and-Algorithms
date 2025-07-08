#include<iostream>
using namespace std;
void merge(int arr[],int s,int e){
 int mid=s+(e-s)/2;
int s1=mid-s+1;
int s2=e-mid;
int l[s1],r[s2];
for(int i=0;i<s1;i++){
    l[i]=arr[i+s];
}
for(int j=0;j<s2;j++){
    r[j]=arr[mid+j+1];
}
int i=0,j=0;
int k=s;
while(i<s1 and j<s2){
if(l[i]<=r[j]){
    arr[k]=l[i];
    i++;
}
else{
    arr[k]=r[j];
    j++;
}
k++;
}
while(i<s1){
    arr[k]=l[i];
    i++,k++;
}
while(j<s2){
    arr[k]=r[j];
    j++,k++;
}
}
void m(int arr[],int s,int e){
int mid=s+(e-s)/2;
m(arr,s,mid);
m(arr,mid+1,e);
merge(arr,s,e);
}
int main(){
int arr[6]={12,543,65,324,564,32};
m(arr,0,5);
for(int i=0;i<6;i++){
    cout<<arr[i]<<" ";
}



    return 0;
}