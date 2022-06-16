

class Solution{
public:
    int findSubString(string str)
    {
        unordered_map<char,int> m;
         int n = str.size();
         set<char>s(str.begin(),str.end());  int k = s.size(); 
         
         int l=0;
         int ans = INT_MAX; int cnt=0;
         for(int i=0;i<n;i++){
            m[str[i]]++;
                
            while(m.size()==k){
                ans = min(ans,i-l+1);
                m[str[l]]--; 
                if(m[str[l]]==0) m.erase( str[l] );
                l++;
            }
        }
        return ans;
    }
    };


Given a string 's'. The task is to find the smallest window length that contains all the characters of the given string at least one time.
For eg. A = aabcbcdbca, then the result would be 4 as of the smallest window will be dbca.

 

