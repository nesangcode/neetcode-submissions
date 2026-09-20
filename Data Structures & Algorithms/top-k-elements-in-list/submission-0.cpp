class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // track the freq
        map<int, int> f;
        vector<pair<int, int>> fnl;
        for(auto &el: nums){
            ++f[el];
        }

        for(auto &[num, freq]: f){
            fnl.emplace_back(freq, num);
        }

        sort(fnl.rbegin(), fnl.rend());

        vector<int> out;

        for(int i = 0; i < k; i++){
            out.emplace_back(fnl[i].second);
        }

        return out;
    }
};
