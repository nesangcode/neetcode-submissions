class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
        int k = 0;
        for(auto &ch: order){
            m[ch] = k++; 
        }
        return is_sorted(words.begin(), words.end(), [&](string &a, string &b){
            for(int i = 0; i < min(a.size(), b.size()); i++){
                if(m[a[i]] != m[b[i]]){
                    return m[a[i]] < m[b[i]];
                }
            }
            return a.size()<b.size();
        });
    }
};