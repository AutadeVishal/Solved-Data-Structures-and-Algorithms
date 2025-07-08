int s(int l,int e,int n){
   int mid;
     mid=l+(e-l)/2;

     if(pow(mid,2)==n){
       return mid;
     }
     else if(pow(mid,2)<n && pow(mid+1,2)>n){
       return mid;
     }
     else if(pow(mid,2)>n){
       return s(l,mid-1,n);
     }
     else{
       return s(mid+1,e,n);
     }
}
int floorSqrt(int n)
{return s(0,n,n);
   
   
}
