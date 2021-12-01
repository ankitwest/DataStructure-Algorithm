//  wrong solution
// do check ones

vi fun(string s,int st,int end){
    vi v;  int cnt=0;
    REP(i,st,end){
        if(s[i]=='1') cnt++;
        else if(s[i]=='0')  if(cnt) v.pb(cnt),cnt=0;
    }
    if(cnt) v.pb(cnt);
    return v;
}
void solve(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    map<int,int>m;
    rep(i,0,n) m[s[i]-'a']++;
    int maxi=-1; int make=-1;
    tr2(x,y,m) {
        if(y>maxi) maxi=max(y,maxi),make=x;
    }
    // deb(maxi);
    char c = make+'a';
    // deb(c);
    rep(i,0,n){
        if(s[i]==c) s[i]='1'; else s[i]='0';
    }
    int first_zero =-1; int last_zero =-1;
    rep(i,0,n) if(s[i]=='0') first_zero=i;
    REV(i,n-1,0) if(s[i]=='0') last_zero=i;
         
    int ans=0;
    if(k==0 and first_zero!=-1){
         ans = -1;
    }else {
        if(first_zero==-1) ans = n;
        else{
            ans = first_zero + (n - last_zero - 1);
            vi ones = fun(s,first_zero,last_zero);
            k--;
            sort(all(ones),greater<int>());
            int i=0;
            while(k-- and i<ones.size()) 
                ans += ones[i++];
        }
    }
    debug(ans);
}
