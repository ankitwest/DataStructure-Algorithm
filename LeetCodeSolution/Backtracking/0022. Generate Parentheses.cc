class Solution {
public:
    vector<string> result;
    void helper(int open,int close,int n,string temp){
        if(temp.size()==2*n){
            result.push_back(temp);
            return ;
        }
        if(open<n) helper(open+1,close,n,temp+"(");
        if(close<open) helper(open,close+1,n,temp+")");
    }
    vector<string> generateParenthesis(int n) {
        if(n==1) return {"()"};
        helper(0,0,n,"");
        return result;
    }
};

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Input: n = 1
Output: ["()"]

// TC - 4^n
