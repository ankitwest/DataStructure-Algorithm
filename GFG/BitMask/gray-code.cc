class Solution{
      public:
    vector<string> generate(int n){
        if(n==1) return {"0","1"};
        vector<string> temp = generate(n-1);
        vector<string> ans;
        for(int i=0;i<temp.size();i++){
            ans.push_back("0"+temp[i]);
        }
        for(int i=temp.size()-1;i>=0;i--){
            ans.push_back("1"+temp[i]);
        }
        return ans;
    }
    vector<string> graycode(int n)
    {
        return generate(n);
    }
};
Expected Time Complexity: O(2n)
