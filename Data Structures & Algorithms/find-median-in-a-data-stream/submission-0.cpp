class MedianFinder {
public:
    multiset<int> s, s2;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(s2.empty()){
            s2.insert(num);
            return;
        }

        if(s.empty()){
            s.insert(num);
            if(*s.begin() > *s2.begin()){
                s.swap(s2);
            }
            return;
        }

        if(num >= *s2.begin()){
            s2.insert(num);
            if((s2.size()-s.size()) >= 2){
                s.insert(*s2.begin());
                s2.erase(s2.begin());
            }
        } else {
            s.insert(num);
            if(s.size()>s2.size()){
                s2.insert(*s.rbegin());
                s.erase(--s.end());
            }
        }
    }
    
    double findMedian() {
        if(s.size()!=s2.size()){
            return *s2.begin();
        }
        return ((double)*s2.begin()+*s.rbegin())/2.0; 
    }
};
