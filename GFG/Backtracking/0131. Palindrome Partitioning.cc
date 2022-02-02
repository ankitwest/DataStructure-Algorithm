class Solution {
public:
    vector<vector<string>> ans;
        vector<string> v;
    
    void func(string &s,int index){
        if(index==s.size()){
            ans.push_back(v);
            return ;
        }
        
        for(int i=index;i<s.size();i++){
            if(isPalin(s,index,i)){
                v.push_back(s.substr(index,i-index+1));
                func(s,i+1);
                v.pop_back();
            }
        }
        return ;
    }
    
    vector<vector<string>> partition(string s) {
        func(s,0);
        return ans;
    }
private:
    bool isPalin(string &s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
};


Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
