class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,r=matrix.size()*matrix[0].size()-1;

        while(l<=r){
            int mid = (l+r)/2;
            int &el = matrix[mid/matrix[0].size()][mid%matrix[0].size()];
            if(el > target){
                r=mid-1;
            } else if (el < target){
                l=mid+1;
            } else {
                return true;
            }
        }
        return false;
    }
};
