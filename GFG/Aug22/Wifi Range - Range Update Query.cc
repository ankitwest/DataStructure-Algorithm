//range update point query
class Solution{
    public:
    bool wifiRange(int N, string s, int x){
        vector<int> prefix(N+1,0);
        for(int i=0;i<s.size();i++){
            if(s[i] == '1'){
                int l = max(0,i - x);
                int r = min(i + x,N-1);
                prefix[l]++;
                prefix[r+1]--;
                // cout<<i<<" "<<l<<" "<<r<<" ";
            }
            // cout<<endl;
        }
        
        // for(int i=0;i<=N;i++)
        //     cout<<prefix[i]<<" ";
        // cout<<endl;
        
        for(int i=1;i<=N;i++)
            prefix[i] += prefix[i-1];
            
        // for(int i=0;i<=N;i++)
        //     cout<<prefix[i]<<" ";
        // cout<<endl;
        
        for(int i=0;i<N;i++) //last one will be zero
            if(prefix[i]==0) return false;
            
        return true;
    }
};
