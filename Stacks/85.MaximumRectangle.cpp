class Solution {
public:
vector<int> prevsmaller(vector<int>&arr){
    stack<int>st;
    vector<int>ans(arr.size(),-1);
    for(int i=0;i<arr.size();i++){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
        ans[i]= st.empty()? -1 : st.top();
         
         st.push(i);
    }
    return ans;
}
vector<int> nextsmaller(vector<int>&arr){
    stack<int>st;
    vector<int>ans(arr.size(),arr.size());
    for(int i=arr.size()-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            st.pop();
        }
      ans[i] = st.empty() ? arr.size() : st.top();
         st.push(i);
    }
    return ans;
}
    int findarea(vector<int>&arr){

            vector<int>next=nextsmaller(arr);
            vector<int>prev=prevsmaller(arr);
            int max=0;
            int val;
        for(int i=0;i<arr.size();i++){
            int l=arr[i];
            int b=next[i]-prev[i]-1;
             val=l*b;
             if(max<val) max=val;
        }
        return max;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
      

        vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), 0));

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
              if (matrix[i][j] == '1') {
                    ans[i][j] = (i == 0) ? 1 : ans[i-1][j] + 1; 
                } else {
                    ans[i][j] = 0;
                }
            }
        }
        int m=0;
        int val;
        for(int i=0;i<matrix.size();i++){
            vector<int>row=ans[i];
            val=findarea(row);
            if(val>m) m=val;
        }
        return m;


    }

};
