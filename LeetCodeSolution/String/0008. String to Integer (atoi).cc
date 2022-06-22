class Solution {
private:
  bool isDigit(char ch){
    return ch>='0' and ch<='9';
  }
public:
  int myAtoi(string s) {
    const int n = s.size();
    if(n==0) return 0;

    int i = 0;
    while(i<n && s[i]==' ') i++;
    
    bool isNeg = false;

    if(i < n){
      if(s[i] == '-') isNeg = true,i++;
      else if (s[i] == '+') i++;
    }

    int result = 0;
    while(i < n && isDigit(s[i])){  // until digit-character or len
      int digit = s[i] - '0';

      if((result > INT_MAX/10) or (result == INT_MAX/10 and digit>7))  // to avoid integer overflow
          return isNeg ? INT_MIN : INT_MAX;

      result = result*10 + digit; 
      i++;
    }
    return isNeg ? -result : result;
  }
};Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (l
