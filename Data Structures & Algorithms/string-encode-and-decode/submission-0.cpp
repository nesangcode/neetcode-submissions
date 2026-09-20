class Solution {
public:

    string encode(vector<string>& strs) {
        string str = "";
        for(auto &el: strs){
            str += to_string(el.length()) + ":" + el;
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> fin;
        for(int itr = 0; itr < s.length();){
            int lgth = 0;
            while(itr < s.length() && s[itr] != ':'){
                lgth = lgth*10 + s[itr]-'0';
                itr++;
            }

            itr++;
            int target=itr+lgth;
            string res;
            while(itr < s.length() && itr < target){
                res += string(1, s[itr]);
                itr++;
            }
            fin.emplace_back(res);
        }
        return fin;
    }
};
