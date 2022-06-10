class Solution {
public:
    bool isPalin(string &s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    
    vector<vector<string>> ans;
    vector<string> v;
    
    void func(string &s,int index){
        if(index==s.size()){
            ans.push_back(v);
            return ;
        }
        
        for(int idx=index;idx<s.size();idx++){
            if(isPalin(s,index,idx)){
                v.push_back(s.substr(index,idx-index+1));
                func(s,idx+1);
                v.pop_back();
            }
        }
        return ;
    }
    
    vector<vector<string>> partition(string s) {
        func(s,0);
        return ans;
    }
};

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
