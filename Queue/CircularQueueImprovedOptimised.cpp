class Solution {
  public:
    int circularTour(vector<int>& a1, vector<int>& a2) {
        int balance=0;
        int start=0;
        int deficit=0;
        for(int i=0;i<a1.size();i++){
            balance+=a1[i]-a2[i];
            if(balance<0){
                start=i+1;
                deficit+=balance;
                balance=0;
            }
    }
    if (balance+deficit>=0) return start;
    return -1;
}};
