class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;

        vector<int> res(temperatures.size(),0);
        int i = 0;
        for(auto&el: temperatures){
            while(!s.empty()){
                auto &[v, idx] = s.top();
                if(v>=el) break;
                res[idx] = i-idx;
                s.pop();
            }
            s.emplace(el, i);
            i++;
        }
        return res;
    }
};
