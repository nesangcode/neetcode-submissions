class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        pair<int, int> ans;
        vector<int>idx(nums.size());
        iota(idx.begin(), idx.end(), 0);

        sort(idx.begin(), idx.end(), [&](int &a, int &b){
            return nums[a] < nums[b];
        });
        sort(nums.begin(), nums.end());

        for(auto &el: idx){
            cout << el << " ";
        } cout << '\n';

        pair<int, int> sent={-1, -1};

        while(i<j){
            while(i<(j-1) && (nums[i]+nums[j]) < target){
                i++;
            }
            if(i<j && (nums[i]+nums[j]) == target){
                
                pair<int, int> fnd_pr = {min(idx[i], idx[j]), max(idx[i], idx[j])};
                cout << fnd_pr.first << " " << fnd_pr.second << "kucing meow\n";
                if(sent.first == -1){
                    sent = fnd_pr;
                } else if(fnd_pr.first < sent.first){    
                    sent = fnd_pr;
                }
            }
            j--;
        }
        return {sent.first, sent.second};
    }
};
