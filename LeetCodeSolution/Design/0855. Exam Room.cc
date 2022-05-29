class ExamRoom {
public:
    set<int> s;
    int last;
    ExamRoom(int n) {
        last = n-1;
    }
    
    int seat() {
        if(s.empty()){
            s.insert(0);
            return 0;
        }
        
        // now we check over all the intervals
        int dist = INT_MIN; int pos = -1;
        
        //[0,1st occupied seat]
        if(s.find(0)==s.end()){
            if(*s.begin()-0 > dist){
                dist = *s.begin();
                pos = 0;
            }
        }
        
        // [1st occupied seat,2nd occupied seat]
        int left = 0;
        for(auto right:s){
            if((right-left)/2 > dist){
                dist = (right-left)/2;
                pos = left + dist;
            }
            left = right;
        }
        
        //[last occupied seat,n-1]
        if(s.find(last)==s.end()){
           if(last- left > dist){
                dist = last - left;
                pos = last;
           }
        }
       
        s.insert(pos);
        return pos;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
