

#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int solve(string s, int n, int l, int r, int i){
    if(l<0 || l>n)
        return 0;
    if(l==r){
        if(i<s.length()){
            if(s[i]=='l')
                return 1+solve(s,n,l-1,r,i+1);
            else
                return 1+solve(s,n,l+1,r,i+1);
        }
    }
    if(i==s.length())
        return 0;
    int ans=0;
    //exclude
    ans+=solve(s,n,l,r,i+1);
    //include
    if(s[i]=='l')
        ans+=solve(s,n,l-1,r,i+1);
    else
        ans+=solve(s,n,l+1,r,i+1);
    return ans;
}

int main()
{   
    string s;
    cin>>s;
    int n,l,r;
    cin>>n>>l>>r;
    int ans=solve(s,n,l,r,0);
    cout<<ans;
    return 0;
}



// rrlrlr
// 6
// 1
// 2

// output
// r
// rlr
// lrr
// rrl
// rlrlr
// rrllr
// rrlrl
// 7

class Solution2():
    def count_unique_subsequence(self, s, start, dest, n):
        def count_unique(s, index, curr, dest, n, d):
            if (index, curr) in d:
                return d[(index, curr)]
            
            result = set([])
            if index == len(s):
                return result
            
            result.update(count_unique(s, index + 1, curr, dest, n, d))
            if s[index] == 'l':
                if curr > 0:
                    next_loc = curr - 1
                    if next_loc == dest:
                        result.add('l')
                    for r in count_unique(s, index + 1, next_loc, dest, n, d):
                        result.add('l' + r)
            else:
                if curr + 1 < n:
                    next_loc = curr + 1
                    if next_loc == dest:
                        result.add('r')
                    for r in (count_unique(s, index + 1, next_loc, dest, n, d)):
                        result.add('r' + r)
            
            d[(index, curr)] = result
            return result
        
        return len(count_unique(s, 0, start, dest, n, {}))
        
s = Solution2()
s.count_unique_subsequence('rrlrlr', 1, 2, 6)
