//Div 1

#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<(x)<<endl

void solveA(){
     int n;
    string s;
    cin >> n >> s;
    if (n % 2 != 0)
         {debug(-1);return ;}
 
    int left = 0, right = 0;
    for (char c : s)
        if (c == '(') left++; else right++;
 
    if (left != n / 2)
        {debug(-1);return ;}
 
 
    int i=0 , start=0, preSum=0, ans=0;
    while(i<n){
        if(preSum==0 and s[i]==')')
            start=i;
        if(preSum==-1 and s[i]=='(')
            ans += i-start+1;
 
        preSum += s[i]== '(' ? +1 : -1;
        i++;
    }
    cout<<ans<<endl;
}
 
int32_t main() {
       ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
      freopen("input.txt", "r", stdin);
 
      solveA();
}
 
