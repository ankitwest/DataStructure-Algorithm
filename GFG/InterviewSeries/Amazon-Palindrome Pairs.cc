class Solution{   
  public:
    // Function to check if a palindrome pair exists
    bool isPalin(string s){
        int n = s.size(); int i=0;
        while(i<n/2){
            if(s[i]!=s[n-1-i]) return false;
            i++;
        }
        return true;
    }
    bool palindromepair(int n, string arr[]) {
        unordered_map<string,int>m;
        for(int i=0;i<n;i++){
            m[arr[i]]=i;
        }
        
        // "" and checking self palindrome
        if(m.find("")!=m.end()){
            for(int i=0;i<n;i++){
                if(isPalin(arr[i])) return true;
            }
        }
        // "abc"  "xyxcba"     
        //  1. "xyx" is palin and we find rev of "cba"
        //  2. "cba" is palin and we find rev of "xyx"
        // we do this for all the length 
        

        for(int i=0;i<n;i++){
            string a = arr[i];
            for(int j=0;j<a.size();j++){
                string left = a.substr(0,j);
                string leftrev = string(left.rbegin(),left.rend());
                string right = a.substr(j);
                string rightrev = string(right.rbegin(),right.rend());
                
                if(m.find(rightrev)!=m.end() and m[rightrev]!=i and isPalin(left)) return true;
                if(m.find(leftrev)!=m.end() and m[leftrev]!=i and isPalin(right)) return true;
            }
        }
        return false;
        // time complexity by substr is O(L)
        // So -> TC = O(N*L*L)
    }
  };
