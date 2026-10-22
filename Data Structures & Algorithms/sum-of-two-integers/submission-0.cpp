class Solution {
public:
    int getSum(int a, int b) {
        return 2*(a&b)+(a^b);
    }
};
