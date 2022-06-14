class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(); int m = t.size();
        unordered_map<char,int> mp;
        for(auto ch:t) mp[ch]++;
        int count = mp.size();
        
        int i=0,l=0; int ans = INT_MAX; string str="";
        while(i<n){
            mp[s[i]]--;
            if(mp[s[i]]==0) count--;
            
            while(count==0){
                if(i-l+1<ans) ans = i-l+1 ,str = s.substr(l,ans);
                
                mp[s[l]]++;
                if(mp[s[l]]>0) count++;
                l++;
            }
            i++;
        }
        return str;
    }
};
