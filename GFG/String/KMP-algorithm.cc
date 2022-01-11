1
batmanandrobinarebat
bat

Your Output: 
0 0 0 0 1 2 3 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 2 3    // lps
1 18 
  
  
  

class Solution{
   public:
        vector <int> search(string pat, string txt)
        {
           vector<int> v;      // a bit change from last one 
           string t = pat + "#" + txt;
           int n = t.size();
           int lps[n];
           memset(lps,0,sizeof(lps));
           int i=1,len = 0;
           
           while(i<n){
               if(t[i]==t[len]){
                  lps[i] = len+1;
                  len++;
                  i++;
               }else{
                  if(len>0)
                    len = lps[len-1];
                    else{
                        lps[i]=0;
                        i++;
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
