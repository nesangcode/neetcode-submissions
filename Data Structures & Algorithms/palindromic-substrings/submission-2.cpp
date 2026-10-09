class Solution {
public:
    int countSubstrings(string s) {
        int sum=0;
        for(int i = 0; i < s.size(); i++){
            int x=i,y=i;
            while(x>=0&&y<s.size()){
                if(s[x]==s[y]){
                    sum++;
                    x--, y++;
                    continue;
                }
                break;
            }
            x=i,y=i+1;
            while(x>=0&&y<s.size()){
                if(s[x]==s[y]){
                    sum++;
                    x--, y++;
                    continue;
                }
                break;
            }
        }
        return sum;
    }
};
