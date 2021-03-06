class Solution{
public:
        vector <int> search(string pat, string txt)
        {
           long long t=0,p=0;
           int n = txt.size(); int m = pat.size();
           
           int q = 1e9+7; int d = 256; long long h =1;
           
           // The value of h would be "pow(d, M-1)%q"
           for(int i=1;i<m;i++)
               h = (h*d)%q;
           
            // Calculate the hash value of pattern and first window of text
           for(int i=0;i<m;i++){
               t = (t*d+txt[i])%q;
               p = (p*d+pat[i])%q;
           }
           
           vector<int> v;
           for(int i=0;i<=n-m;i++){
               if(t==p){
                   if(txt.substr(i,m)==pat)
                    v.push_back(i+1); //index+1
               }
               
               if(i<n-m){
                   t = (d*(t-txt[i]*h) + txt[i+m]) %q;
                   if(t<0) t+=q;
               }
           }
           if(v.size()==0) return {-1};
           return v;
        }
        };

How does the above expression work? 

This is simple mathematics, we compute decimal value of current window from previous window. 
For example pattern length is 3 and string is “23456” 
You compute the value of first window (which is “234”) as 234. 
How  will you compute value of next window “345”? You will do (234 – 2*100)*10 + 5 and get 345.


        
        

Input:
S = "batmanandrobinarebat", pat = "bat"
Output: 1 18
Explanation: The string "bat" occurs twice
in S, one starts are index 1 and the other
at index 18. 
