class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>m;
       for(auto i:s){
        m[i]++;
       }
       char maxchar;
       int maxfreq=0;
       for(auto i:m){
        if(i.second>maxfreq){
            maxfreq=i.second;
            maxchar=i.first;
        }
       }
       if(maxfreq>(s.size()+1)/2) return "";
       int i=0;
       int size=s.size();
      vector<char> result(size); 
       while(m[maxchar]-- > 0){
        result[i]=maxchar;
        i+=2;
       }
       for(auto it:m){
        while(it.second-- >0){
            if(i>=size) i=1;
            result[i]=it.first;
            i+=2;
        }
       }
    return string(result.begin(),result.end());
    }
};
