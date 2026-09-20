class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while(i <= j){
            while(i < j && !isAlphanum(s[i])) i++;
            while(j > i && !isAlphanum(s[j])) j--;
            if(!isAlphanum(s[i])) break;
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
                
            i++, j--;
        }
        return true;
    }
    bool isAlphanum(char ch){
        return ch >= 'A' && ch <= 'Z'
            || ch >= 'a' && ch <= 'z' ||
            ch >= '0' && ch <= '9';
        
    }
};
