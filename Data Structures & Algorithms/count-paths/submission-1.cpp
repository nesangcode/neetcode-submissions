class Solution {
public:
    int uniquePaths(int m, int n) {
        int sum = 1;
        vector<int> v(max(0, n-2), 0);
        iota(v.rbegin(), v.rend(), 2);
        vector<int> b(max(0,m-2), 0);
        iota(b.rbegin(), b.rend(), 2);

        for(int i = 2; i <= (m+n-2); i++){
            sum *= i;
            while(!v.empty() && sum%v.back()==0){
                sum /= v.back();
                v.pop_back();
            }

            while(!b.empty() && sum%b.back()==0){
                sum /= b.back();
                b.pop_back();
            }
        }
        return sum;
    }
};
