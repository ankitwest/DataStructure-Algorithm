class Solution {
public:
    // string is used in place of stack for optimization.
    string removeKdigits(string num, int k) {
        int n = num.size();
        string ans="";
        
        for(char c:num){
            while(ans.size() and ans.back()>c and k)
                k--,ans.pop_back();
            
           ans.push_back(c);
            if(ans.size()==1 and c=='0') ans.pop_back();
        }
        while(ans.size() and k--)
            ans.pop_back();
        
        return ans.size()==0?"0":ans;
    }
};

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
