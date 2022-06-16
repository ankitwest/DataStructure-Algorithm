class Solution {
public:     // here previous contribution is included so no need of map and previous occurence
    long long countVowels(string s) {
        auto isVowel = [&](char ch){
            if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u') return true;
            return false;
        };
        
        int n = s.size();
        long long ans = 0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                ans += (long long)(i + 1) * (long long)(n - i);
            }
        }
        return ans;
    }
};




class SolutionFollowUp {
public:  // if previous contribution wasn't included 
    long long countVowels(string s) {
        auto isVowel = [&](char ch){
            if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u') return true;
            return false;
        };
        
        int n = s.size();
        unordered_map<int,int> m;
        long long ans = 0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i])){
                if(m.find(s[i])==m.end())
                    ans += (i + 1) * (n - i);
                else
                    ans += (i + m[s[i]]) * (n - i);
            }
            m[s[i]] = i;
        }
        return ans;
    }
};

      
                    
// A character at position pos can be present in substrings starting at i and substrings ending at j,
// where 0 <= i <= pos (pos + 1 choices) and pos <= j <= len (len - pos choices)
// so there are total (len - pos) * (pos + 1) substrings that contain the character word[pos]

// (You can see from above example that e is at position 2 and it's present in substrings "abei", "bei", "ei", "abe", "be", "e"
// (0 <= start <= pos and pos <= end <= len) and same will be true for each vowel.


// From this observation we can generalise the occurence of each vowel in the string as

// here len(abei) = 4
// a,  pos = 0, count = (4 - 0) * (0 + 1) = 4
// e,  pos = 2, count = (4 - 2) * (2 + 1) = 6
// i,  pos = 3, count = (4 - 3) * (3 + 1) = 4
 

// count = (i + 1) * (n - i)
                    

 
class Solution2 {
public: 
    long long countVowels(string s) {
        int n = s.size();
        auto isVowel = [&](char ch){
            if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u') return true;
            return false;
        };
        vector<long long> dp(n,0);
        
        if(isVowel(s[0])) 
            dp[0] = 1;
        
        for(int i=1;i<n;i++){
            if(isVowel(s[i])) 
                dp[i] = dp[i-1] + i + 1;
            else
                dp[i] = dp[i-1];
        }
        return accumulate(dp.begin(),dp.end(),0LL);
    }
 };
 
 
 
 Input: word = "aba"
Output: 6
Explanation: 
All possible substrings are: "a", "ab", "aba", "b", "ba", and "a".
- "b" has 0 vowels in it
- "a", "ab", "ba", and "a" have 1 vowel each
- "aba" has 2 vowels in it
Hence, the total sum of vowels = 0 + 1 + 1 + 1 + 1 + 2 = 6. 
                    

        
