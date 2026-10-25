class MyHashSet {
public:
    vector<bool> vv;
    MyHashSet() {
        vv.assign(1000001, 0);
    }
    
    void add(int key) {
        vv[key] = 1;
    }
    
    void remove(int key) {
        vv[key] = 0;
    }
    
    bool contains(int key) {
        return vv[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */