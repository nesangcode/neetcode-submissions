class StockSpanner {
public:
    stack<int> ss,s2;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int sum=1;
        while(!ss.empty()){
            if(ss.top()>price)break;
            sum += s2.top();
            s2.pop();
            ss.pop();
        }
        ss.emplace(price);
        s2.emplace(sum);
        return sum;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */