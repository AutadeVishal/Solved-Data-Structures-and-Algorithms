class Solution {
  public:
  void dfs(int curr,vector<bool>&visited,vector<vector<int>>&adjlist){
      visited[curr]=true;
      for(auto &nbor:adjlist[curr]){
          if(!visited[nbor]){
              dfs(nbor,visited,adjlist);
          }
      }
  }
    int maxRemove(vector<vector<int>>& stones, int n) {
       vector<vector<int>>adjlist(n);
       unordered_map<int,int>row;
       unordered_map<int,int>col;
       for(int i=0;i<stones.size();i++){
           int currNodeRow=stones[i][0];
           int currNodeCol=stones[i][1];
           int currNode=i;
           if(row.find(currNodeRow)!=row.end()){
               adjlist[currNode].push_back(row[currNodeRow]);
               adjlist[row[currNodeRow]].push_back(currNode);
           }
             if(col.find(currNodeCol)!=col.end()){
               adjlist[currNode].push_back(col[currNodeCol]);
               adjlist[col[currNodeCol]].push_back(currNode);
           }
           row[currNodeRow]=currNode;
           col[currNodeCol]=currNode;
       }
        //now we have graph and we can find components and return the answer as no. of elemtns-no. of components
        //this formualla is derived for that watch strver starting video
        vector<bool>visited(n,false);
        int numberOfComponents=0;
          for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, adjlist);
                numberOfComponents++;
            }
        }
        return n-numberOfComponents;
    }
};

//Whole Game lies in how to create a graph
//I Created graph using indexes and connected nodes if there exists any latest previous node in that row/column .
