class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>> mp;
        int i=0;
        for(auto &c : s){
            mp[c].push_back(i++);
        }
        
        int cnt = 0; bool f = true;
        for(auto &w : words){
            int prev = -1;
            f = true;
            for(auto &c:w){
                auto &v = mp[c];
                auto it = upper_bound(v.begin(),v.end(),prev);
                if(it==v.end())  {f = false; break;}
                prev = *it;
            }
            if(f) cnt++;
        }
        return cnt;
    }
};
