class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       vector<int> before(26,0),now(26,0);
        for(auto c:s1) before[c-'a']++;
        
        int l = s1.size();

        for(int i=0;i<s2.size();i++){
            now[s2[i]-'a']++;
            if(i>=l) now[s2[i-l]-'a']--;
            if(now==before) return true;
        }
        return false;
    }
};

