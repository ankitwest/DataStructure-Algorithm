
class Solution{
  public:
void permutation(string s,int i,vector<string> &ans){
        if(i==s.size()){
            ans.push_back(s);
            return;
        }
        
        for(int j=i;j<s.size();j++){
            swap(s[i],s[j]);
            permutation(s,i+1,ans);
            swap(s[i],s[j]);
        }
    }
    vector<string>find_permutation(string S)
    {
        vector<string> ans;
        permutation(S,0,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


Input: ABC
Output:
ABC ACB BAC BCA CAB CBA
Explanation:
Given string ABC has permutations in 6 
forms as ABC, ACB, BAC, BCA, CAB and CBA .
Example 2:

Input: ABSG
Output:
ABGS ABSG AGBS AGSB ASBG ASGB BAGS 
BASG BGAS BGSA BSAG BSGA GABS GASB 
GBAS GBSA GSAB GSBA SABG SAGB SBAG 
SBGA SGAB SGBA
Explanation:
Given string ABSG has 24 permutations.
