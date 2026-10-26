class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int now[2] = {-1, -1};
        int sc[2] = {0, 0};

        vector<int> fin;
        for(auto &el: nums){
            if(now[0]==el){
                ++sc[0];
                continue;
            }

            if(now[1]==el){
                ++sc[1];
                continue;
            }

            if(sc[0]==0){
                now[0] = el;
                ++sc[0];
                continue;
            }

            if(sc[1]==0){
                now[1] = el;
                ++sc[1];
                continue;
            }

            --sc[0], --sc[1];
        }

        for(int i = 0; i < 2; i++){
            int frq = 0;
            for(auto &el:nums){
                frq+= (el==now[i]);
            }
            if(frq > (nums.size()/3)){
                fin.emplace_back(now[i]);
            }
        }
        return fin;
    }
};