/*You are required to complete this method*/
class Solution {
  public:
    int circularTour(vector<int>& a1, vector<int>& a2) {
        for(int i=0;i<a1.size();i++){
            int gasleft=0;
            int t=a1.size();
            int j=i;
            while(t--){
                if(a1[j]+gasleft>a2[j]){
                    gasleft+=(a1[j]-a2[j]);
                }
                else break;
                j=(j+1)%a1.size();
            }
            if(t==-1) return i; 
        }
        return -1;
    }
};
