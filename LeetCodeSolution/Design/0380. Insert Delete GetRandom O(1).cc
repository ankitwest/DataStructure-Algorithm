class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> m;
public:
    RandomizedSet(){
   
    }
    
    bool insert(int val) {
        if(m.find(val) != m.end()) return false;
        nums.push_back(val);
        m[val] = nums.size() - 1;   // element -> index
        return true;
    }
    
    bool remove(int val) { // a=[8,4,3,2], m={[8,0],[4,1],[3,2],[2,3]}, val=4
        if (m.find(val) == m.end()) return false;
        int last = nums.back();   // 2
        nums[m[val]] = last;  //a=[8,2,3,2],
        nums.pop_back();  //a=[8,2,3],
        
        m[last] = m[val];  //m={[8,0],[4,1],[3,2],[2,1]}
        m.erase(val);  // m={[8,0],[3,2],[2,1]}
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};



/*remove
rand() function gives random value in the range of 0 to RAND_MAX(whose value is 32767)

            // For example: a=[8,4,3,2], m={[8,0],[4,1],[3,2],[2,3]}, val=4, last=2
	        // After a[m[val]]=a.back(); a=[8,2,3,2], m={[8,0],[4,1],[3,2],[2,3]}
	        // After a.pop_back(); a=[8,2,3], m={[8,0],[4,1],[3,2],[2,3]}
	        // After m[last]=m[val]; a=[8,2,3], m={[8,0],[4,1],[3,2],[2,1]}
	        // After m.erase(val); a=[8,2,3], m={[8,0],[3,2],[2,1]}
            
            
The order of elements is not important in the data structure. If we use an array as the data structure, insertion at the end will be in O(1) time but searching whether the element is already present in the array will take O(N) time. 
Removal of the element will require searching for the element which will take O(N) time and left shifting the subsequent array elements will also take O(N) time. 
Getting random element will take O(1) time using the rand() function. So, we need some additional data structure that allows us to locate the array index for removal and also to search whether the element is already present or not. 
This data structure should do these tasks in O(1) time. Hashmap fulfils our requirements.
*/

//s.begiN()+ rand
/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
