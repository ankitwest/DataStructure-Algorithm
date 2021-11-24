#include <bits/stdc++.h>
using namespace std;

#define pii                  pair<int, int>
#define mii                  map<int , int>
#define vi                   vector<int>
#define vpii                 vector<pii>
#define vvi                  vector<vector<int>>
#define pb          push_back
#define ff          first
#define ss          second

#define fill0(v)        fill(all(v),0);
#define mem0(arr)   memset(arr, 0, sizeof(arr))    //for array
#define lb(v,x) lower_bound(v.begin(),v.end(),x) - v.begin();
#define ub(v,x) upper_bound(v.begin(),v.end(),x) - v.begin();
#define tr(x,v)         for(auto &x:v)
#define tr2(x,y,m)      for(auto &[x,y]:m)

#define rep(i,a,n)      for(int i = a ; i < n ; i++)
#define REP(i,a,n)      for(int i = a ; i <= n ; i++)
#define all(v)      v.begin(),v.end()
#define cy cout<<"YES"<<endl
#define cn cout<<"NO"<<endl
#define ln cout<<"\n";
#define debug0(x) cout<<(x)<<" "
#define debug(x) cout<<(x)<<endl
#define debug2(x,y) cout<<(x)<<" "<<(y)<<endl
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl

#define int long long
const int mod  =  1e9+7;

void solveC(){
    int n; cin>>n;
    string s; cin>>s;
    for(int i=0;i<n-1;i++){
        if(s[i] == 'a' && s[i+1] == 'a') {
            debug(2); return;
        }
    }
    for(int i=0;i<n-2;i++){
        if(s[i] == 'a' && s[i+2] == 'a') {
            debug(3); return;
        }
    }
    for(int i=0;i<n-3;i++){
        if(s[i] == 'a' && s[i+3] == 'a' && s[i+2] != s[i+1]){
            debug(4); return;
        }
    }
    for(int i=0;i<n-6;i++){
        if(s[i] == 'a' && s[i+3] == 'a' && s[i+6] == 'a'
            && s[i+1] == s[i+2] && s[i+4] == s[i+5] && s[i+1] != s[i+4]){
            debug(7);return;
        }
    }
    cout<<"-1\n";
}  

int32_t main(){
    vector<int> v={1,2,3};
    int a = lb(v,3);
    debug(a);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("hey2.txt", "r", stdin);
    int t;  cin>>t;
    while(t--) 
       solveC();       // cout << "Case #" << i+1 << ": ";
    return 0;
}

// void shortest_distance(vector<vector<int>>&matrix){
// 	    int n = matrix.size();
// 	    for(int k=0; k<n; k++) {
// 	        for(int i=0; i<n; i++) {
// 	            for(int j=0; j<n; j++) {
// 	                if(matrix[i][k]==-1 || matrix[k][j]==-1) continue;
// 	                if(matrix[i][j]==-1) 
// 	                	matrix[i][j] = matrix[i][k] + matrix[k][j];
// 	                else matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][j]);
// 	            }
// 	        }
// 	    }
// 	}


// Node* constTree(int pre[],int len,int l,int r,int ptr){
// 	if(ptr>=len) return NULL;
// 	if(l>r) return NULL;
// 	int x = pre[ptr];
// 	if(pre[ptr]<l or pre[ptr]>r) return NULL;

// 	Node* root = new Node(pre[ptr]);
// 	ptr++;

// 	root->left = constTree(pre,len,l,x-1,ptr);
// 	root->right = constTree(pre,len,x+1,r,ptr);
	
// 	return root;
// }


