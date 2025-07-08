class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
       unordered_set<string>st(wordList.begin(),wordList.end());
       queue<pair<string,int>>q;
       q.push({startWord,1});
        unordered_map<string,bool>visited;
        for(int i=0;i<wordList.size();i++){
            visited[wordList[i]]=false;
        }
        visited[startWord]=true;
       while(!q.empty()){
           string currword=q.front().first;
           int distance=q.front().second;
           q.pop();
           if(currword==targetWord) return distance;
           for(int j=0;j<currword.size();j++){
               char orignalchar=currword[j];
               for(char ch='a';ch<='z';ch++){
                   currword[j]=ch;
                   if(st.find(currword)!=st.end() && !visited[currword]){
                       q.push({currword,distance+1});
                       visited[currword]=true;
                       
                   }
               }
               currword[j]=orignalchar;
           }
       }
        return 0;
    }
};
