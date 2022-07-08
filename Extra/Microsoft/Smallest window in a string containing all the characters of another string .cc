// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    
    //both traversal is independent of each other
    // TC - O(N) + O(N)
    string smallestWindow (string s, string p)
    {
        unordered_map<int,int> m;
        for(auto c:p) m[c-'a']++;
        int sz = m.size(); int l = 0;
        
        int mini = INT_MAX; 
        int start = 0; int end = 0;
        for(int i=0;i<s.size();i++){
            m[s[i]-'a']--;
            if(m[s[i]-'a']==0) sz--;    
            
            while(sz==0){
                if(i-l+1 < mini){
                    mini = i-l+1;
                    start = l;
                    end = i;
                }
                m[s[l]-'a']++;
                if(m[s[l]-'a']>0) sz++; 
                l++;
            }
        }
        if(mini==INT_MAX) return "-1";
        
        return s.substr(start,end-start+1);
    }
};

//eraseing give problem in 
// can use freq array instead
// zoomlazapzo
// oza

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
