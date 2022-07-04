1
batmanandrobinarebat
bat

Your Output: 
0 0 0 0 1 2 3 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 2 3    // lps
1 18 
  
  
//   The time complexity of KMP algorithm is O(n)

class Solution{
   public:
        vector <int> search(string pat, string txt)
        {
           vector<int> v;      // a bit change from last one 
           string s = pat + "#" + txt;
           int n = s.size();  int i=1,len = 0;
           int lps[n]; memset(lps,0,sizeof(lps));
           lps[0] = 0;
           
           while(i<n){
               if(s[i]==s[len]){
                  lps[i++] = ++len;
               }else{
                  if(len>0)
                    len = lps[len-1];
                    else{
                        lps[i++]=0;
                    }
               }
           }
        //   for(int i=0;i<n;i++) cout<<lps[i]<<" ";  cout<<endl;
    
        int m = pat.size();
        for(int i=1;i<n;i++){
            if(lps[i]==m)
                v.push_back(i-2*m+1);
        }
        
        if(v.size()) return v;
        v.push_back(-1);
        return v;
        
        }
     
};



// Longest Prefix Suffix 

Input: s = "abab"
Output: 2
Explanation: "ab" is the longest proper 
prefix and suffix. 
Example 2:

Input: s = "aaaa"
Output: 3
Explanation: "aaa" is the longest proper 
prefix and suffix. 
  
  
  
class Solution{
  public:		
	int lps(string s) {
	    int n = s.size(); int i=1,len=0;
	    vector<int> lps(n);
	    lps[0]=0;
	    
	   while(i<n){
	       if(s[i]==s[len]){
	           lps[i++] = ++len;
	       }else{
	             // their is some suffix is present possibly of 
	           // length zero which is equal to preffix between string 0 to i-1
	           // check wheter the prefix+1 is equal to ith elem or set
	           // to len pointer to zero if not
	           if(len>0){
	               len = lps[len-1];
	           }else{
	               lps[i++] = 0;
	           }
	       }
	       //cout<<len<<" ";
	   }
	   //cout<<endl;
	   //   for(int i=0;i<n;i++) cout<<lps[i]<<" ";  cout<<endl;
	   return len;
	}
};
