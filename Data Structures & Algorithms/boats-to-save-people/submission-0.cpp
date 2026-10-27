class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size()-1;
        int boat = 0;
        while(i<j){
            int sum = people[i]+people[j];
            if(sum <= limit){
                i++, j--;
                ++boat;
            } else {
                ++boat;
                j--;
            }
        }

        if(i==j) ++boat;
        return boat;
    }
};