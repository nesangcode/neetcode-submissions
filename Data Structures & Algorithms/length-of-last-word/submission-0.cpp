class Solution {
public:
    int lengthOfLastWord(string s) {
        int itr=s.size()-1;
        while(itr>=0&&s[itr]==' ')--itr;
        int sum=0;
        while(itr>=0&&((s[itr]>='a'&&s[itr]<='z')||(s[itr]>='A'&&s[itr]<='Z'))){
            --itr;
            ++sum;
        }
        return sum;
    }
};