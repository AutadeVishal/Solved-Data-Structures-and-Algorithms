class TrieNode {
    public:
    TrieNode *  children[26];
    bool isend=false;
    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};
class Trie{
    public:
    TrieNode * root;
    Trie(){
        root=new TrieNode();
    }
    void insert(string s){
        TrieNode * curr=root;
        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            if(!curr->children[index]){
                curr->children[index]=new TrieNode();
            }
            curr=curr->children[index];
        }
        curr->isend=true;
    }
    
};

//Ignore Above Code it is just implementation of Trie Tree
//Real Masala is Thiss..
class Solution{
public:
void solve(TrieNode * curr,string pre,vector<string>&v){
    if(curr && curr->isend==true){
        v.push_back(pre);
    }
    for(int i=0;i<26;i++){
        if(curr && curr->children[i]){
            string nextpre=pre+char('a'+i);
            solve(curr->children[i],nextpre,v);
            
        }
    }
}
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie * T=new Trie();
        string pre="";
        for(int i=0;i<n;i++){
            T->insert(contact[i]);
        }
        vector<vector<string>>ans;
        TrieNode * curr=T->root;
        for(int i=0;i<s.size();i++){
           pre+=s[i];
           vector<string>v;
         if(curr)  curr=curr->children[s[i]-'a'];
           solve(curr,pre,v);
        if(v.empty()) {
            v.push_back("0");
            
        }
           ans.push_back(v);
        }
        return ans;
    }
};
