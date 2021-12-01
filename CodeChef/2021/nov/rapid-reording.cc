// check it is wrong

void solve(){
    int n;cin>>n;
    int no = n;
    n*=2;
    vi a(n);rep(i,0,n) cin>>a[i];
    int maxi = *max_element(all(a));
    mii m;
    rep(i,0,n) m[i]++;

    int cnt =0; tr2(x,y,m) if(y==2) cnt++;

    set<int> s(all(a)); print(s); 
    // int x = *s.begin();  debug(x);

    if(n==1){
            if (a[0] != a[1]) debug(-1);
            else debug(a[0]);
            return;
    }

    if(m[n-1]==1 and m[(n-1)/2]==3 and cnt==n-2){ print(s);}
    else debug(-1);

}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE    
    freopen("abc2.txt", "r", stdin); freopen("err.txt", "w", stderr);
#endif  
    int t;  cin>>t;
    while(t--) 
       solve();       // cout << "Case #" << i+1 << ": ";
    return 0;
}
