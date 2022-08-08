https://practice.geeksforgeeks.org/contest/interview-series-62/problems/

// series 62


class Solution {
  public:
    string removeReverse(string s) {
        map<int,int> m;
        for(auto c:s) m[c-'a']++;
        
        int n = s.size();
        int i=0; int j = n-1;
        bool left = true;
        while(i<j){
            if(left){
                if(m[s[i]-'a'] > 1) {
                    m[s[i]-'a']--; 
                    s[i] = '$';
                    left = false;
                }
                i++;
            }else if(!left){
                if(m[s[j]-'a'] > 1) {
                    m[s[j]-'a']--; 
                    s[j] = '$';
                    left = true;
                }
                j--;
            }
        }
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i] != '$') ans += s[i];
        }
        if(!left) reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
