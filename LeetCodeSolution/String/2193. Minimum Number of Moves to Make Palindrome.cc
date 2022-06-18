class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.size();
        int left = 0 , right = n-1 , ans = 0;
        while(left<right){
            int l = left, r = right;
            while(s[l]!=s[r]) r--;
            if(l==r){
                swap(s[r],s[r+1]); 
                ans++;
            //just did to prevent next time
            }else{
                while(r<right){
                    swap(s[r],s[r+1]); ans++; r++; 
                }
              // one position secured
                left++; right--;
            }
        }
        return ans;
    }
};


Input: s = "aabb"
Output: 2
Explanation:
We can obtain two palindromes from s, "abba" and "baab". 
- We can obtain "abba" from s in 2 moves: "aabb" -> "abab" -> "abba".
- We can obtain "baab" from s in 2 moves: "aabb" -> "abab" -> "baab".
Thus, the minimum number of moves needed to make s a palindrome is 2.
