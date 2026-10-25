class NumMatrix {
public:
    vector<vector<int>> dp;

    NumMatrix(vector<vector<int>>& matrix) {
        dp.assign(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i = 0; i < matrix.size(); i++){
            int sum = 0;
            for(int j = 0; j < matrix[i].size(); j++){
                dp[i][j] = matrix[i][j]+sum;
                if(i>0) dp[i][j] += dp[i-1][j];
                sum += matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = dp[row2][col2];
        int i = 0;
        if(row1>0){
            i++;
            res -= dp[row1-1][col2];
        }
        if(col1>0){
            i++;
            res -= dp[row2][col1-1];
        }

        if(i==2){
            res += dp[row1-1][col1-1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */