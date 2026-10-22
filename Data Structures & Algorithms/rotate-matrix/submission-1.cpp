class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size()/2; i++){
            for(int j = i; j < (matrix.size()-i-1); j++){
                int x=matrix.size()-1-j,y=i;
                for(int k = 0; k < 3; k++){
                    int nx=matrix.size()-1-y;
                    int ny=x;
                    swap(matrix[x][y], matrix[nx][ny]);
                    x=nx;
                    y=ny;
                }
            }
        }
    }
};
