class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> fin;
        for(auto &el: asteroids){
            if(el>0){
                fin.emplace_back(el);
            } else {
                bool f=true;
                while(!fin.empty()){
                    if(fin.back()<0){
                        break;
                    }
                    if(fin.back()==-el){
                        fin.pop_back();
                        f=false;
                        break;
                    } else if(fin.back()>-el){
                        f=false;
                        break;
                    } else {
                        fin.pop_back();
                    }
                }
                if(f) fin.emplace_back(el);
            }
        }
        return fin;
    }
};