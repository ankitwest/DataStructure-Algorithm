

class Solution{
public:

    //Function to check if two arrays are equal or not.
    bool check(vector<ll> A, vector<ll> B, int N) {
        unordered_map<int,int> mp;
       for(auto it: A) {
           mp[it]++;
       }
       
       for(auto it: B) {
           mp[it]--;
           if(mp[it]<0) return false;
       }
       return true;
    }
    
    bool check2(vector<ll> A, vector<ll> B, int N) {
        // for unique elements in array
        int x1 = 0; int x2 = 0;
        for(auto i:A) x1 ^= i;
        for(auto i:B) x2 ^= i;
        
        int x = x1 ^ x2;
        if(x==0) return 1;
        return 0;
    }
    };
    
    /*
2
3 3
2 2
*/
