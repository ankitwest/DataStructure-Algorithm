class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy=0;int yx=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]=='x' and s2[i]=='y') 
                xy++;
            else if(s1[i]=='y' and s2[i]=='x') 
                yx++;
        }
        if(xy%2 != yx%2) 
            return -1;
        int ans = xy/2+yx/2+(xy%2)*2;
        return ans;
    }
};

Example 1:

Input: s1 = "xx", s2 = "yy"
Output: 1
Explanation: Swap s1[0] and s2[1], s1 = "yx", s2 = "yx".
Example 2:

Input: s1 = "xy", s2 = "yx"
Output: 2
Explanation: Swap s1[0] and s2[0], s1 = "yy", s2 = "xx".
Swap s1[0] and s2[1], s1 = "xy", s2 = "xy".
Note that you cannot swap s1[0] and s1[1] to make s1 equal to "yx", cause we can only swap chars in different strings.
