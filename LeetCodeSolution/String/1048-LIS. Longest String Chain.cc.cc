class Solution {
public:         // using substr
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[&](string &a,string &b){
            return a.size() < b.size();
        });
            
        // for(auto i:words) cout<<i<<" "; cout<<endl;
        map<string,int> m;
        
        int max_chain = 1;
         for(int i=0;i<words.size();i++){
            string word = words[i];
            for(int j=0;j<word.size();j++){
               string sub = word.substr(0,j) + word.substr(j+1);
                if(m[sub] + 1 > m[word])
                    m[word] = m[sub] + 1;
               // m[word] = max(m[word], m[sub] + 1);
            }
             if(m[word] > max_chain)
                 max_chain = m[word];
            // max_chain = max(max_chain, m[word]);
        }
        return max_chain;
    }
};






// tle? why?
// lis  TC - O(N^2)*L
class Solution2 {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[&](string &a,string &b){
            return a.size() < b.size();
        });
        
        
        auto check = [&](string a,string b) -> bool{
            if(a.size() != b.size() + 1) return false;
            int i=0;int j=0;
            while(i<a.size()){
                if(a[i]==b[j]) i++,j++;
                else i++;
            }
            if(i==a.size() and j==b.size()) return true;
            return false;
        };
        
        vector<int> lis(n,1);        
        int maxi = 1;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j]) and lis[i] < lis[j] + 1){
                    lis[i] = lis[j] + 1;
                }
            }
            if(lis[i] > maxi){
                maxi = lis[i];
            }
        }
        return maxi;
    }
};

  

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
