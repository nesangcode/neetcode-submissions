class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(auto &el: stones){
            pq.emplace(el);
        }
        while(pq.size() >= 2){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(a==b) continue;
            if(a>b) swap(a, b);
            pq.emplace(b-a);
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};
