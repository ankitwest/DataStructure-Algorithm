class Solution {
public:   // substr
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
                m[word] = max(m[word] , m[sub] + 1);
            }
            max_chain = max(max_chain,m[word]);
        }
        return max_chain;
    }
};

Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
Example 2:

Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
