class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        vector<int>endPoints(1e5,1e8);
        queue<pair<int,int>>q;
        q.push({0,start});
        endPoints[start]=0;
        //storing minimum steps required to get this value
        int mod=1e5;
        if(start==end) return 0;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int steps=curr.first;
            int currCalculation=curr.second;
            for(int i=0;i<arr.size();i++){
                int updatedCalculation=(currCalculation*arr[i])%mod;
                
                if(endPoints[updatedCalculation]>steps+1){
                    endPoints[updatedCalculation]=steps+1;
                    if(updatedCalculation==end) return steps+1;
                    q.push({steps+1,updatedCalculation});
                }
            }
        }
        return -1;
    }
};
