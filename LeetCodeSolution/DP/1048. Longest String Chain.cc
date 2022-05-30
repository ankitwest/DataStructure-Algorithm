

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


// lis
class Solution2 {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[&](string &a,string &b){
            return a.size() < b.size();
        });
        
        
        auto check = [&](string a,string b) -> bool{
            int i=0;int j=0;
            while(i<a.size()){
                if(a[i]==b[j]) i++,j++;
                else i++;
            }
            if(i==a.size() and j==b.size()) return true;
            return false;
        };
        
        vector<int> lis(n,1);        
        int max_chain = 1;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j]) and lis[i] < lis[j] + 1){
                    lis[i] = lis[j] + 1;
                }
            }
            max_chain = max(max_chain,lis[i]);
        }
        return max_chain;
    }
};
  
