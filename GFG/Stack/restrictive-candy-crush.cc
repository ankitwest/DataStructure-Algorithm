class Solution{
public:
    string Reduced_String(int k,string s){
        if(k==1) return "";
        stack<pair<char,int>>st;
       for(auto& ch:s){
           if(st.empty() or st.top().first!=ch){
               st.push({ch,1});
           }else if(st.top().second==k-1) {
               st.pop();
           }else {
               int freq = st.top().second;
               st.pop();
               st.push({ch,freq+1});
           }
       }
       string ans="";
       while(!st.empty()){
           char ch = st.top().first;
           int freq = st.top().second;
           st.pop();
           while(freq--) ans += ch;
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};
Expected Time Complexity: O(|s|)
