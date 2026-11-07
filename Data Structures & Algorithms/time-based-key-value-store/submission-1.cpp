class TimeMap {
public:
    map<pair<string,int>, string> hi;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hi[{key,timestamp}] = value;
    }
    
    string get(string key, int timestamp) {
        auto it = hi.upper_bound({key, timestamp});
        if(it==hi.begin()) return "";
        --it;
        if(it->first.first != key) return "";
        return (it->second);
    }
};
