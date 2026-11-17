class MyQueue {
public:
    stack<int> st, stt;
    MyQueue() {
        
    }

    void ref(){
        if(!stt.empty()) return;

        while(!st.empty()){
            stt.push(st.top());
            st.pop();
        }
    }

    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        ref();
        int x = stt.top();
        stt.pop();
        return x;
    }
    
    int peek() {
        ref();
        return stt.top();
    }
    
    bool empty() {
        ref();
        return stt.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */