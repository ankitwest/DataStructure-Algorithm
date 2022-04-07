

// only these 2 methods
class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
         int n=s.size(); vector<int> f(256,0);
        int left=0,right=0;
        int len=0; 
        while(right<n){
            f[s[right]]++;
            while(f[s[right]]>1){
                f[s[left]]--;
                left++;
            }
            len = max(len,right-left+1);
            right++;
        }
        return len;
    }
};



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        set<char> st;      int n=s.size();
        int i=0; int j=0;
        int len = 0;
        while(j<n){
            if(st.count(s[j])==0){
                st.insert(s[j]);
                len = max(len,j-i+1);
                j++;
            }else{
                st.erase(s[i]);
                i++;
            }
        }
        return len;
    }
};



Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
