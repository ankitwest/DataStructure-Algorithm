class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.length();    
        map<char,vector<int>> m;
        for(int i=0;i<n;i++) m[s[i]].push_back(i);
        
        long ans = 0;
        for(auto [x,index] :m){
            for(int i=0;i<index.size();i++){
                int left  = (i==0) ? index[i] + 1 : index[i] - index[i-1];
                int right = (i==index.size()-1) ? n - index[i] : index[i+1] - index[i];
                ans += left * right;
            }
        }
        return ans;
    }
};

// Every letter in the string S eventually "contributes" to the final answer.
// Consdier the example S = "ABC".
// A will contribute 3, respectively in substring "A", "AB" and "ABC".
// B will contribute 4, respectively in substring "B", "AB", "BC" and "ABC".
// C will contribute 3, respectively in substring "C", "BC" and "ABC".
// The final answer is equal to the sum of "C[i] = contribution of i-th letter".
// Claim: C[i] = L[i] * R[i], where L[i] indicates the number of letters between s[i] and the last occurence (assuming that we go through the string from left to right) of the letter 's[i]'; R[i] is defined similarily by assuming that we go through the string from right to left.


class Solution {
public:
    int uniqueLetterString(string s) {
        long ans = 0; int n = s.size();
        for(int i=0;i<n;i++){
            int l=i-1; while(l>=0 and s[l] != s[i]) l--;
            int r=i+1; while(r<n and s[r] != s[i]) r++;
            
            ans += (i - l) * (r - i);
        }
        return ans;
    }
};

