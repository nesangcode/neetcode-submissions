class Solution {
public:
    void inc(unordered_map<int, int> &alp, multiset<int> &ms, char ch){
        if(alp[ch]!=0)
        ms.erase(ms.find(alp[ch]));
        // inc
        ms.insert(++alp[ch]);
    }

    void dec(unordered_map<int, int> &alp, multiset<int> &ms, char ch){
        ms.erase(ms.find(alp[ch]));

        // dec
        --alp[ch];
        if(alp[ch] != 0)
        ms.insert(alp[ch]);
    }
    int characterReplacement(string s, int k) {
        int fnl = 0;
        int lgth = 0;

        int itr = 0, i = 0;

        unordered_map<int, int> alp;
        multiset<int> ms;
        while(itr < s.length()){
            ++lgth;
            inc(alp, ms, s[itr]);

            while((lgth - *ms.rbegin()) > k){
                dec(alp, ms, s[i]);
                i++; --lgth;
            }

            fnl = max(fnl, lgth);
            itr++;
        }
        return fnl;
    }
};
