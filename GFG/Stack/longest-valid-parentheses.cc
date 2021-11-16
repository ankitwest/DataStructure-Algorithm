// Solved using loop from front and back

class Solution{
public:
    int maxLength(string S){
        int open=0,close=0,ans=0;
        for(int i=0;i<S.size();i++){
            if(S[i]=='(') open++;
            else close++;
            if(open==close) ans = max(ans,open+close);
            else if(close>open) close=0,open=0;
        }
        
        open=0,close=0;
        for(int i=S.size()-1;i>=0;i--){
            if(S[i]==')') open++;
            else close++;
            if(open==close) ans = max(ans,open+close);
            else if(close>open) close=0,open=0;
        }
        return ans;
    }
};
