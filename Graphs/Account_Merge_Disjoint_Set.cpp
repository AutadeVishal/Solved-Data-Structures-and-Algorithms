class Solution {
  public:
  int findParent(int node,vector<int>&parents){
      if(parents[node]==node){
          return node;
      }
      return parents[node]=findParent(parents[node],parents);
  }
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        unordered_map<string,int>whose;
        vector<int>parents(accounts.size());
        for(int i=0;i<accounts.size();i++){
            parents[i]=i;
        }
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
               string email=accounts[i][j];
               if(whose.find(email)!=whose.end()){
                   int parent1=findParent(i,parents);
                   int parent2=findParent(whose[email],parents);
                   if(parent1!=parent2){
                       parents[parent1]=parent2;
                   }
               }
               else{
                   whose[email]=i;
               }
            }
        }
        
        
         unordered_map<int, set<string>> merged;
        for (auto it = whose.begin(); it != whose.end(); ++it) {
            string email = it->first;
            int idx = it->second;
            int parent = findParent(idx, parents);
            merged[parent].insert(email);
        }

        vector<vector<string>> result;
        for (auto it = merged.begin(); it != merged.end(); ++it) {
            int idx = it->first;
            set<string>& emailSet = it->second;
            vector<string> entry;
            entry.push_back(accounts[idx][0]); 
            entry.insert(entry.end(), emailSet.begin(), emailSet.end());
            result.push_back(entry);
        }
         return result;
    }
};
