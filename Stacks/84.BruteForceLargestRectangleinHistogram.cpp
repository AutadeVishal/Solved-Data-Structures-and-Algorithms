class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max=0;
        for(int i=0;i<heights.size();i++){
            int width=1;
            int val;
            int j=i-1;
            while(j>=0){
                if(heights[j]>=heights[i]){
                    width++;
                }
                else{
                    break;
                }
                j--;
            }
            j=i+1;
            while(j<heights.size()){
                if(heights[j]>=heights[i]){
                    width++;
                }
                else{
                    break;
                }
                j++;
            }
            val=width*heights[i];
            if(max<val) max=val;
        }
        return max;
    }
};
