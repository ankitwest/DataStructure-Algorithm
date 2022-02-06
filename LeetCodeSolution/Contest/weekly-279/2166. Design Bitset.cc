class Bitset {
public:
    string s = "";
    int len = 0; int flip_ctr=0; int ones=0,zero=0;
    
    Bitset(int size) {
       len = size;
        for(int i=0;i<len;i++) s+='0';
        ones = 0; zero = len;
        flip_ctr=0;
    }
    
    void fix(int idx) {
        if(flip_ctr&1){
            if(s[idx]=='1')   // original mein 1 current mein 0
                s[idx]='0',ones++,zero--;     // original mein 0 current mein 1
        }else{
            if(s[idx]=='0')
                s[idx]='1',ones++,zero--;
        }
    }
    
    void unfix(int idx) {
         if(flip_ctr&1){
            if(s[idx]=='0')   // original mein 0 current mein 1
                s[idx]='1',ones--,zero++;     // original mein 1 current mein 0
        }else{
            if(s[idx]=='1')
                s[idx]='0',ones--,zero++;
        }
    }
    
    void flip() {
        flip_ctr++;
       swap(ones,zero);
    }
    
    bool all() {
        return ones==s.size();
    }
    
    bool one() {
        return ones>0;
    }
    
    int count() {
        return ones;
    }
    
    string toString() {
        if(flip_ctr&1){
            string x = s;
            for(int i=0;i<s.size();i++)
               if(s[i]=='0') x[i]='1'; else x[i]='0';
            return x;
        }
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
 
 
 Input
["Bitset", "fix", "fix", "flip", "all", "unfix", "flip", "one", "unfix", "count", "toString"]
[[5], [3], [1], [], [], [0], [], [], [0], [], []]
Output
[null, null, null, null, false, null, null, true, null, 2, "01010"]


Constraints:

1 <= size <= 105
0 <= idx <= size - 1
At most 105 calls will be made in total to fix, unfix, flip, all, one, count, and toString.
At least one call will be made to all, one, count, or toString.
At most 5 calls will be made to toString.
