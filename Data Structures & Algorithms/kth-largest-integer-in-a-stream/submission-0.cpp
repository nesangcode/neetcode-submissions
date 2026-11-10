class KthLargest {
public:
priority_queue<int>pq;
int K;
    KthLargest(int k, vector<int>& nums) {
        this->K = k;
        for(auto&el:nums){
            pq.emplace(-el);
        }
    }
    
    int add(int val) {
        pq.emplace(-val);
        while(pq.size()>K){
            pq.pop();
        }
        return -pq.top();
    }
};
