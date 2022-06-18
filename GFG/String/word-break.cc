
// passing string
class Solution1
{
public:
    unordered_map<string,int> freq;
    bool helper(string A,vector<string> &B){
        if(A.size()==0)
            return true;
            
        for(int i=0;i<A.length();i++){
            string left = A.substr(0,i+1);
            if(freq.find(left)!=freq.end()){
                string right = A.substr(i+1);
                if(helper(right,B)==true) 
                    return true;
            }
        }
        return false;
    }
    int wordBreak(string A, vector<string> &B) {
      for(int i=0;i<B.size();i++){
          freq[B[i]]++;
      }
      return helper(A,B);
    }
};




// passing index
class Solution
{
public:
    int solve(int i,string s,vector<string>& wordDict){
        if(i==s.size()){
            return true;
        }
        
        bool ans = false;
        for(int k=i;k<s.size();k++){
            string str = s.substr(i,k-i+1);
            if(find(wordDict.begin(), wordDict.end(), str) != wordDict.end()){
                if(solve(k+1,s,wordDict))
                    ans = true;
            }
        }
        return ans;
    }
    int wordBreak(string A, vector<string> &B) {
    
      return solve(0,A,B);
    }
};
