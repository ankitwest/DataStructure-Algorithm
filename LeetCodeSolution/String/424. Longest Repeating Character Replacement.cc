
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> m; int n = s.size();
        int i=0; int ans = 0; int max_repeating = 0;
        for(int j=0;j<n;j++){
            m[s[j]]++;
            int window_len = j-i+1;
            for(auto [x,y]:m) max_repeating = max(max_repeating,y);
            if(window_len - max_repeating<=k){
                ans = max(ans,window_len);
            }else{
                m[s[i]]--;
                i++;
            }
        }
       return ans; 
    }
};

Optimization



class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> m; int n = s.size();
        int i=0; int ans = 0; int max_repeating = 0;
        for(int j=0;j<n;j++){
            m[s[j]]++;
            max_repeating = max(max_repeating,m[s[j]]);  //freq update for fresh element 
            
            while(j-i+1 - max_repeating > k){
                m[s[i]]--;
                i++;
            }
            if(j-i+1 - max_repeating<=k){
                ans = max(ans,j-i+1);
            }   
        }
       return ans; 
    }
};
