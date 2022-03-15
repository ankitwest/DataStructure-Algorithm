class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = "";
        int cnt=0;
        while(b.size()>s.size()){
            s+=a;
            cnt++;
        }
        
        if(s.find(b)!=-1)
            return cnt;
        // if(s.find(b)!=string::npos)
        //     return cnt;
        
        s+=a;
        cnt++;
        if(s.find(b)!=-1)
            return cnt;
        return -1;
        
    }
};
Example 1:

Input: a = "abcd", b = "cdabcdab"
Output: 3
Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.
Example 2:

Input: a = "a", b = "aa"
Output: 2
