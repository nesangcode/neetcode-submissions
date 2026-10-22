class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        for(int i = 0; i <= 31; i++){
            sum += (n & (1 << i))!=0;
        }
        return sum;
    }
};
