class Solution{
public:
  int minimumSum(string s) {
        // code here
        int n = s.length();
        int sum = 0, prev;
        
        // checking if the string is not palindrome
        for(int i = 0; i < n/2; ++i)
            if(!(s[i] == '?' || s[n-1-i] == '?' || s[i] == s[n-1-i]))
                return -1;
                
        // filling the question marks with the character corresponding to the same index from backwards
        // because the string has to be a palindrome
        
        for(int i = 0; i < n/2; ++i)
            if(s[i] == '?' ^ s[n-1-i] == '?')
            {
                if(s[i] == '?')
                    s[i] = s[n-1-i];
                else
                    s[n-1-i] = s[i];  
            }
        
        // obtaining the first alphabet
        for(int i = 0; i < n/2; ++i)
            if(s[i] != '?')
            {
                prev = s[i];
                break;
            }
            
        for(int i = 0; i < n; ++i)
            if(s[i] != '?')
            {
                sum += abs(s[i] - prev);
                prev = s[i];
            }

        return sum;
    }
    };

Input: S = a???c??c????
Output: 4
Explanation:
We can see that we can make the string
palindrome. Now to get minimum sum we should
replace all the '?' between 'a' and 'c' with
'b' and all the '?' between two 'c' with 'c'.
So after replacing all the '?' the string: 
abbbccccbbba.
The sum of differences of adjacent characters is 4.   

Input: S = a???c??c???c
Output: -1
Explanation:
It is not possible to make the string palindrome.



