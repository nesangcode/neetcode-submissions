class Solution {
public:
    bool pal(string &s, int l, int r){
        while(l < r){
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]) return pal(s, l, r-1) || pal(s, l+1, r);
            l++, r--;
        }
        return true;
    }
};