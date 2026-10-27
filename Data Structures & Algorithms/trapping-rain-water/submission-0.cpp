class Solution {
public:
    int trap(vector<int>& height) {
        vector<pair<int,int>> v;
        long long res = 0;
        for(int i = 0; i < height.size(); i++){
            int &el = height[i];

            while(!v.empty() && v.back().first < el){
                if(v.size()==1){
                    v.pop_back();
                    break;
                }

                if(v[v.size()-2].first == v.back().first){
                    v.pop_back();
                    continue;
                }

                int h = min(v[v.size()-2].first, el)-v.back().first;
                int idx = i-v[v.size()-2].second-1;
                res += 1LL*h*idx;
                v.pop_back();
            }
            v.emplace_back(el, i);
        }
        return res;
    }
};
