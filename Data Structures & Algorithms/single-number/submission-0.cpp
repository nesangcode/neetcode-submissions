class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,bool> m;
        for(auto &el: nums){
            if(m.count(el)){
                m.erase(el);
            } else {
                m[el] = 1;
            }
        }
        return m.begin()->first;
    }
};