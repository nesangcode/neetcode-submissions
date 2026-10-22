class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        for(int i = 0; i < 16; i++){
            bool bit1= (n & (1 << i)) != 0;
            bool bit2= (n & (1 << (31-i))) != 0;

            if(bit1^bit2){
                n ^= (1<<i);
                n ^= (1<<(31-i));
            }
        }
        return n;
    }
};
