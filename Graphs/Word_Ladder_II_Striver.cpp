class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList)  {
       
        int level=0;
        vector<string>vec;
        vec.push_back(beginWord);
        queue<vector<string>>q;
        q.push(vec);
        vector<vector<string>>ans;
        unordered_set<string>st(wordList.begin(),wordList.end());
        
        
        int maxdist=INT_MAX;
        unordered_set<string>usedInPreviousLevel;
        usedInPreviousLevel.insert(beginWord);
        
        
        while(!q.empty()){
            vector<string>v=q.front();
            int currDist=v.size();
            q.pop();
            if(currDist>maxdist) continue;
            if(currDist>level){
                level++;
                for(auto &word:usedInPreviousLevel){
                    st.erase(word);
                }
                 usedInPreviousLevel.clear();
            }
            string currWord=v.back();
            usedInPreviousLevel.insert(currWord);
            if(currWord==endWord){
                ans.push_back(v);
                maxdist=currDist;
                continue;
            }
            for(int i=0;i<currWord.size();i++){
                char orignalChar=currWord[i];
                for(char ch='a';ch<='z';ch++){
                    currWord[i]=ch;
                    if(st.find(currWord)!=st.end() ){
                        v.push_back(currWord);
                        q.push(v);
                        v.pop_back();
                    }
                    
                }
                currWord[i]=orignalChar;
            }
            
        }
        return ans;
    }
};
