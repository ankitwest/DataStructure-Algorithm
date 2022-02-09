// Not understood

class Solution {
public:
    bool palin(string s,int i,int j){
        while(i<j and s[i]==s[j]){
            i++,j--;
        }
        return i>=j;
    }
    bool check(string &a,string &b){
        int n = a.size();
        int left=0;int right=n-1;
        while(left<=right and a[left]==b[right]){
                left++,right--;
        }
        return palin(a,left,right) or palin(b,left,right);
    }
    bool checkPalindromeFormation(string a, string b) {
        return check(a,b) or check(b,a);
    }
};


Input: a = "ulacfd", b = "jizalu"
Output: true
Explaination: Split them at index 3:
aprefix = "ula", asuffix = "cfd"
bprefix = "jiz", bsuffix = "alu"
Then, aprefix + bsuffix = "ula" + "alu" = "ulaalu", which is a palindrome.
