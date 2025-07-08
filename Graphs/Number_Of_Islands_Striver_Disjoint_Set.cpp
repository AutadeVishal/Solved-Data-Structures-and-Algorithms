class Solution {
  public:
  int findParent(int node,vector<int>&parents){
      if(parents[node]==node)return node;
      return parents[node]=findParent(parents[node],parents);
  }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        vector<int>parents(n*m);
        int size=n*m;
        for(int i=0;i<size;i++){
            parents[i]=i;
        }
        int nr[]={1,0,-1,0};
        int nc[]={0,1,0,-1};
        int count=0;
        vector<int>ans;
        for(int i=0;i<operators.size();i++){
            int row=operators[i][0];
            int col=operators[i][1];
            if(visited[row][col]){
                ans.push_back(count);
                continue;
            }
            count++;
            visited[row][col]=true;
            for(int j=0;j<4;j++){
                int newrow=nr[j]+row;
                int newcol=nc[j]+col;
                if(newrow<n && newrow>=0 && newcol<m && newcol>=0){
                    if(visited[newrow][newcol]){
                        int  par1=findParent(parents[newrow*m+newcol],parents);
                        int par2=findParent(parents[row*m+col],parents);
                        if(par1!=par2){
                            parents[par1]=par2;
                            count--;
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
