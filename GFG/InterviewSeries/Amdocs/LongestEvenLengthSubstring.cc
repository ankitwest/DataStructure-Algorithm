
class Solution{
public:
    int substr(int n,string str){
        int i = 0; int j = 1;
        int ans = 0;
        auto getDigit = [&](char c){
            return (int)c-'0';
        };
        while(j<n){
            int a = getDigit(str[i]);
            int b = getDigit(str[j]);
            
            if(a==b) ans = max(ans,2);
            int ii=i-1; int jj=j+1;
            while(ii>=0 and jj<n){
                a += getDigit(str[ii]);
                b += getDigit(str[jj]);
                if(a==b){
                    ans = max(ans,jj-ii+1);
                }
                ii--; jj++;
            }
            i++;j++;
        }
        return ans;
    }
    };

Input:
str = 1234123
Output:
4
Explanation:
substring 2341 can be considered as answer,
 since 2+3 = 4+1.
