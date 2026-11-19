class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> v;
        v.reserve(2);
        for(auto&el:tokens){
            if(el=="+"){
                int x = v[v.size()-1]+v[v.size()-2];
                v.pop_back();
                v.pop_back();
                v.emplace_back(x);
            } else if(el=="-"){
                int x = v[v.size()-2]-v[v.size()-1];
                v.pop_back();
                v.pop_back();
                v.emplace_back(x);
            } else if(el=="*"){
                int x = v[v.size()-2]*v.back();
                v.pop_back();
                v.pop_back();
                v.emplace_back(x);
            } else if(el=="/"){
                int x = v[v.size()-2]/v.back();
                v.pop_back();
                v.pop_back();
                v.emplace_back(x);
            } else {
                v.emplace_back(stoi(el));
            }
        }
        return v[0];
    }
};
