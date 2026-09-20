class Solution {
public:
    int maxArea(vector<int>& heights) {
        int mx = 0;
        int i = 0, j = heights.size()-1;
        while(i < j){
            mx = max(mx, (j-i)*min(heights[j], heights[i]));
            if(heights[i] <= heights[j]){
                i++;
            } else {
                j--;
            }
        }
        return mx;
    }
};
