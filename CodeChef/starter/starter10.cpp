#include <bits/stdc++.h>
using namespace std;


#define debug(x) cout<<(x)<<endl
// #define debug2(x,y) cout<<(x)<<" "<<(y)<<endl

#define int long long
// const int mod  =  1e9+7;


void solve()  {
        int a,b,c;cin>>a>>b>>c;

        int mini= min({a,b,c});
            string ans ;
          ans =   (mini ==a) ? "Draw":(mini==b)?"Bob":(mini==c)?"Alice":"False";
        cout<<ans<<endl;
}

void solve2(){
    int n,k,s;cin>>n>>k>>s;
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=2*i-1;
    }
    s-=sum;
    k--;
    int ans = s/k;
    cout<<ans<<endl;
}

void solve3(){
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    int sum=0;
    for(auto &x:arr){
        cin>>x;
    }
    sort(arr.begin(),arr.end());

    for(int i=0;i<k;i++){
        if(arr[i]<0)
            arr[i]*=(-1);
    }

    for(int i=0;i<n;i++){
        if(arr[i]>0)
            sum+=arr[i];
    }
    cout<<sum<<endl;
    

}

void solve4(){
    int n;cin>>n;
    vector<int> a(n),b(n-1),d;
    for(auto &x:a){
        cin>>x;
    }
    for(auto &x:b){
        cin>>x;
    }
    sort(b.begin(),b.end());
    sort(a.begin(),a.end());

    

    for(int i=1;i<n-1;i++){
        int diff=b[i]-b[i-1];
        d.push_back(diff);
    }



    int k=0;
    int ans=0;
   

    int differ;

    if(n==2){
        if(a[1]>b[0]){
            ans = b[0]-a[0];
        } else if(a[1]<b[0]){
            ans = b[0]-a[1];
        }
    }
    else if(n==3){
        differ=b[1]-b[0];
        if(a[1]-a[0]==differ) {
            ans = b[0]-a[0]; 
        }
        else if(a[2]-a[1]==differ){
            ans = b[0]-a[1]; 
        }
        else if (a[2]-a[0]==differ){
            ans = b[0]-a[0]; 
        }
    } else if (n>=4){
        int m=n-1;
        differ=b[m-1]-b[m-2];
        if(a[n-2]-a[n-3]==differ) {
            ans = b[m-1]-a[n-2];   
        }
        else if(a[n-1]-a[n-2]==differ){
            ans = b[m-1]-a[n-1];  
        }
        else if (a[n-1]-a[n-3]==differ){
            ans = b[m-1]-a[n-1];   
        }
    }
    cout<<ans<<endl;

}
      
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("input.txt", "r", stdin);

    int t;  cin>>t;
    while(t--) 
       solve4();       // cout << "Case #" << i << ": ";

    return 0;
}