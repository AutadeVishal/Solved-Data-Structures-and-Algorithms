class Solution {
public:
void solve(string &digits,int index,string output,vector<string>&ans,string mapping[]){
    if(index>=digits.size()){
        ans.push_back(output);
        return ;
    }
    int digit=digits[index]-'0';
    for(int i=0;i<mapping[digit].size();i++){
        char c=mapping[digit][i];
        output.push_back(c);
        solve(digits,index+1,output,ans,mapping);
        output.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        vector<string>ans; 
        if(digits.empty()) return ans;
       
        string output;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,0,output,ans,mapping);
        return ans;
    }
};
