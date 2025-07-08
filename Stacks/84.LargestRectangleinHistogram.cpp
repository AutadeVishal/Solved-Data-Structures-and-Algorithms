class Solution {
public:
vector<int> nextsmall(vector<int>&heights){
    stack<int>st;
    st.push(-1);
    vector<int>ans(heights.size());
    int i=heights.size()-1;
    while( i>=0){
        while(st.top()!=-1 && heights[st.top()]>=heights[i]){
            st.pop();

        }
        int curr=i;
        if(st.top()==-1){
            ans[i]=heights.size()-i;
        }
        else{
        ans[i]=st.top()-i;
        }
        st.push(i);
        i--;
    }
    return ans;
}
vector<int> prevsmall(vector<int>&heights){
    stack<int>st;
    st.push(-1);
    int i=0;
    vector<int>ans(heights.size());
    while(i<heights.size()){
        while(st.top()!=-1 && heights[st.top()]>=heights[i]){
            st.pop();

        }
        int curr=i;
        if(st.top()==-1){
            ans[i]=i+1;
        }
        else{
        ans[i]=i-st.top();
        }
        st.push(curr);
        i++;
    }
    return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        int max=0;
        int l,b;
        vector<int>next=nextsmall(heights);
        vector<int>prev=prevsmall(heights);
        for(int i=0;i<heights.size();i++){
            l=heights[i];
            b=next[i] +prev[i] -1 ;
           if(max<=(l*b)) {
            max=l*b;
           }
        }
        return max;
    }
};
