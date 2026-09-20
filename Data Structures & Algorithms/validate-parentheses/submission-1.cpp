class Solution {
public:
    char fren(char ch){
        map<int, int> fren = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
        };

        for(auto &[x, y]: fren){
            fren[y] = x;
        }

        return fren[ch];
    }
    bool isValid(string s) {
        stack<int> st;

        for(auto &ch: s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            } else {
                if(st.empty() || st.top()!=fren(ch)){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
