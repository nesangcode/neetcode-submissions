class Solution {
public:
    int appendCharacters(string s, string t) {
        int S=s.size(), T=t.size();
        int i=0,j=0;

        while(i<S&&j<T){
            while(i<S&&s[i]!=t[j]){
                i++;
            }
            if(i<S&&s[i]==t[j]){
                i++,j++;
            }
        }

        return (T-j);
    }
};