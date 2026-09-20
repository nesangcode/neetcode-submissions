class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        int S=s.size();
        for(int i = 1; i < S; i++){
            sum += abs(s[i]-s[i-1]);
        }
        return sum;
    }
};