Input:
S = "batmanandrobinarebat", pat = "bat"
Output: 1 18
Explanation: The string "bat" occurs twice
in S, one starts are index 1 and the other
at index 18. 
  
  
 Input: 
S = "abesdu", pat = "edu"
Output: -1
Explanation: There's not substring "edu"
present in S.



class Solution{
  public:
  public:
     void getZarr(string &str,vector<int> &z){
        int L=0,R=0; int n = str.size();
        for(int i=1;i<n;i++){
            if(i>R){
                L = R = i;
                while(R < n and str[R-L] == str[R]) 
                    R++;

                z[i] = R-L;
                R--;
            }else{
                int k = i-L;
                if(z[k] < R-i+1)  z[i] = z[k];
                else {
                    L = i;
                    while(R < n and str[R-L] == str[R])
                        R++;

                    z[i] = R-L;
                    R--;
                }
            }
        }
    }
        vector <int> search(string pat, string txt)
        {
            vector <int> v; 
            
            string concat = pat +'$' + txt;  
            int l = concat.size();

            vector<int> z(l,0);
            getZarr(concat,z);
             
           for(int i=0;i<l;i++){
            if(z[i]==pat.size()) v.push_back(i-pat.size());  
           }
           return v;
        }
};
 
