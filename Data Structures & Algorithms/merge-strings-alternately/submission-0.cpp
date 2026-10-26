class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0;
        string fin;
        while(i<word1.size()&&i<word2.size()){
            fin += word1[i];
            fin += word2[i];
            i++;
        }
        
        while(i<word1.size()){
            fin += word1[i++];
        }

        while(i<word2.size()){
            fin += word2[i++];
        }

        return fin;
    }
};