


class Solution{
public:
    string rremove(string s){
        int i=0; int n = s.size();
        string ans = "";
        while(i<n){
            int j = i+1;
            while(s[i]==s[j]) j++;
            if(j==i+1) ans += s[i];
            i = j;
        }
        if(ans.size()<s.size()) return rremove(ans);
        return ans;
    }
};

Input:
S = "geeksforgeek"
Output: "gksforgk"
Explanation: 
g(ee)ksforg(ee)k -> gksforgk
