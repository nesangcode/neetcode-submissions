class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> rs2;
        vector<vector<string>> res;
        vector<pair<string, string>> v; // {sorted, ori}

        // construct v
        for(auto &el: strs){
            string srted = el;
            sort(srted.begin(), srted.end());
            v.emplace_back(srted, el);
        }

        sort(v.begin(), v.end());

        for(int i = 0; i < v.size(); i++){
            auto &[srted, ori] = v[i];

            if(i!=0 && srted != v[i-1].first){
                res.push_back(rs2);
                rs2.clear();
            }

            rs2.emplace_back(ori);
        }

        if(!rs2.empty()){
            res.push_back(rs2);
        }

        return res;
    }
};
