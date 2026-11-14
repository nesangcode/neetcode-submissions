class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a5=0,a10=0,a20=0;
        for(auto&el:bills){
            if(el==5){
                ++a5;
            } else if(el==10){
                if(a5==0) return false;
                --a5;
                ++a10;
            } else {
                if(a5>0&&a10>0){
                    --a5;
                    --a10;
                    ++a20;
                } else if(a5>=3){
                    a5-=3;
                    ++a20;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};