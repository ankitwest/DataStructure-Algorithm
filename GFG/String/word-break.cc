// GFG

    

class Solution
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



// M-2
    
class Solution
{
public:
    bool wordBreakUtil(int i,int j,int l,string &A,vector<string> &B){
    
        if(j == l){
            if(i == l) return true;
             return false;
         }
    
        if(find(B.begin(),B.end(),A.substr(i,j-i+1))==B.end())  // string from pos i to j
            return wordBreakUtil(i,j+1,l,A,B);
        else{
            if(wordBreakUtil(i,j+1,l,A,B)) return true;
            return wordBreakUtil(j+1,j+1,l,A,B);
        }
    }
    int wordBreak(string A, vector<string> &B) {
      return wordBreakUtil(0,0,A.size(),A,B);
    }
    };        


// M-3

class Solution
{
public:
unordered_map<string,int> dp;
    int solve(string s, vector<string> &arr){
        int l=s.size();
        if(l==0) return 1;
        if(dp[s]!=0) return dp[s];
        
        for(int i=1;i<=l;i++){
            int f=0;
            string str = s.substr(0,i);
            for(int j=0;j<arr.size();j++){
                if (str.compare(arr[j])==0) {f=1; break;}
            }
            if(f==1 and solve(s.substr(i,l-i),arr)==1)   dp[s]=1;
                  
        }
        return dp[s]=-1;
    }
    int wordBreak(string A, vector<string> &B) {
      int x = solve(A,B);
      if(x==1) return 1; else return 0;
    }
};
        
        
        
        
        
        
        
// Leetcode

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        bool dp[len+1];
        memset(dp,false,sizeof(dp));
        dp[0] = true;
        for(int i=1;i<=len;i++){
            for(int j=1;j<=i;j++){
                if(find(wordDict.begin(),wordDict.end(),s.substr(i-j,j)) != wordDict.end() and dp[i-j]){
                    dp[i] = true; 
                }
            }
        }
        return dp[len];
    }
};

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
