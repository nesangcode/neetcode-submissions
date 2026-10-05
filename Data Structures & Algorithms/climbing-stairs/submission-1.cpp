class Solution {
public:
    unordered_map<int, int> res;
    int climbStairs(int n) {
        if(n < 0) return 0;
        if(n==0) return 1;
        if(res.find(n) != res.end()) return res[n];
        return res[n] = climbStairs(n-1)+climbStairs(n-2);
    }
};
