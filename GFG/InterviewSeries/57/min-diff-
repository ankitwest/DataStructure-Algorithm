class Solution {
    int findDiff(int freq1[],int freq2[]){
        int ans = 0;
        for(int i=0;i<26;i++){
            if(freq2[i]>0) ans += abs(freq1[i]-freq2[i]);
        }
        return ans;
    }
  public:
    int minimumDifference(string s, vector<string> list) {
        int d = INT_MAX;
        for(auto word:list){
            int freq1[26]; memset(freq1,0,sizeof(freq1));
            int freq2[26]; memset(freq2,0,sizeof(freq2));
            
            int i=0;
            while(i<word.size()){
                freq1[word[i]-'a']++;
                freq2[s[i]-'a']++;
                i++;
            }
            
            d = min(d,findDiff(freq1,freq2));
            
            int l=0;
            while(i<s.size()){
                freq2[s[i++]-'a']++;
                freq2[s[l++]-'a']--;
               d = min(d,findDiff(freq1,freq2));
            }
        }
        return d;
    }
};
