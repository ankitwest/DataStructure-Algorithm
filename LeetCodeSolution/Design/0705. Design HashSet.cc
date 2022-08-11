class MyHashSet {
public:
    vector<bool> num;
    MyHashSet() {
        num.resize(1e6+1,false); //maximum numbers allowed
    }
    
    void add(int key) {
        num[key] = true;
    }
    
    void remove(int key) {
        num[key] = false;
    }
    
    bool contains(int key) {
        return num[key];
    }
};
