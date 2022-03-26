

class Solution {
public:
    vector<string> v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> result;
    
    void helper(string digits,int ind,string temp){
        if(ind==digits.size()){
            result.push_back(temp);
            return ;
        }
        
        for(int i=0;i<v[digits[ind]-'0'].size();i++){
            helper(digits,ind+1,temp+v[digits[ind]-'0'][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        helper(digits,0,"");
        return result;
    }
};

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
