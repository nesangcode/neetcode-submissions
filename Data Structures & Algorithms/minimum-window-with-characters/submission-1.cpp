class Solution {
public:

    void inc(int &itr, int &lgth, int &freeKey, char &ch, unordered_map<int, int> &freq,
    unordered_map<int, int> &minKey){
        itr++, lgth++;

        if(minKey[ch]!=0 && ++freq[ch]==minKey[ch]) --freeKey;
    }

    void dec(int &b, int &lgth, int &freeKey, char &ch, unordered_map<int, int> &freq,
    unordered_map<int, int> &minKey){
        b++, lgth--;

        if(minKey[ch]!=0 && freq[ch]--==minKey[ch]) ++freeKey;
    }

    string minWindow(string s, string t) {
        int lgth=0, b=0, mn=INT_MAX, freeKey=0;
        int itr=0;
        pair<int, int> s_rng = make_pair(0,0);

        unordered_map<int, int> freq, minKey;
        // precompute minKey
        for(auto &ch: t){
            if(minKey[ch]++ == 0){
                ++freeKey;
            }
        }

        while(itr < s.length()){
            // extend sampai t ketemu
            while(itr < s.length() && freeKey > 0){
                inc(itr, lgth, freeKey, s[itr], freq, minKey);
            }

            // cut the left till key ada 1
            while(freeKey == 0){
                if(lgth < mn){
                    s_rng = make_pair(b, itr);
                    mn = lgth;
                }
                dec(b, lgth, freeKey, s[b], freq, minKey);
            }
        }
        return s.substr(s_rng.first, s_rng.second-s_rng.first);
    }

};
