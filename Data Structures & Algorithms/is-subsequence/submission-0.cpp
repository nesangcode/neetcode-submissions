class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0,j=0;
        int ssz=s.size();
        int tsz=t.size();

        while(i<ssz&&j<tsz){
            while(j<tsz&&t[j]!=s[i]){
                j++;
            }
            if(j<tsz&&t[j]==s[i]){
                i++;
                j++;
            }
        }

        return i==ssz;
    }
};