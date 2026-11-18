class MinStack {
public:
    stack<int> mn, n;
    MinStack() {
        
    }
    
    void push(int val) {
        if(mn.empty()){
            mn.emplace(val);
            n.emplace(val);
        } else {
            mn.emplace(min(val,mn.top()));
            n.emplace(val);
        }
    }
    
    void pop() {
        mn.pop();
        n.pop();
    }
    
    int top() {
        return n.top();
    }
    
    int getMin() {
        return mn.top();
    }
};
