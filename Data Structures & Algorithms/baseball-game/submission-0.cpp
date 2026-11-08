class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum=0;
        vector<int> s;
        for(int i = 0; i < operations.size(); i++){
            string &now=operations[i];
            if(now=="+"){
                s.emplace_back(s[s.size()-1]+s[s.size()-2]);
            } else if(now=="D"){
                s.emplace_back(s[s.size()-1]*2);
            } else if(now=="C"){
                s.pop_back();
            } else {
                s.emplace_back(stoi(operations[i]));
            }
        }
        for(auto &el: s){
            sum += el;
        }return sum;
    }
};