
class Solution {
public:  // TC - O(NlogN+MlogM)
	int findSwapValues(int a[], int n, int b[], int m)
	{
        sort(a,a+n);
        sort(b,b+m); 
        long long sum1 = accumulate(a,a+n,0LL);
        long long sum2 = accumulate(b,b+m,0LL);
        
        if((sum1+sum2)&1) 
            return -1;
        
        if(sum1<sum2){
            set<long long> setB(b,b+m);
            long long req = (sum1+sum2)>>1;
            long long diff = req - sum1;
            for(int i=0;i<n;i++){
                if(setB.find(a[i]+diff)!=setB.end()){
                     return true;
                }
            }
        }else{
            set<long long> setA(a,a+n);
            long long req = (sum1+sum2)>>1;
            long long diff = req - sum2;
            for(int i=0;i<m;i++){
                if(setA.find(b[i]+diff)!=setA.end()){
                     return true;
                }
            }
        }
        return -1;
	}
};

class Solution22 {
    public:   // TC - O(N+M)
	int findSwapValues(int a[], int n, int b[], int m)
	{
        long long sum1 = accumulate(a,a+n,0);
        long long sum2 = accumulate(b,b+m,0);
        
        if(sum2>sum1){
            swap(a,b);
            swap(sum1,sum2);
            swap(n,m);
        }

        if((sum1+sum2)&1) 
            return -1;
        if(sum1<sum2){
            unordered_map<long long,long long> mp;
            for(int i=0;i<m;i++) mp[b[i]] = 1;
            long long req = (sum1+sum2)>>1;
            long long diff = req - sum1;
            for(int i=0;i<n;i++){
                if(mp.count(a[i]+diff)) return true;
            }
        }else{
            unordered_map<long long,long long> mp;
            for(int i=0;i<n;i++) mp[a[i]] = 1;
            long long req = (sum1+sum2)>>1;
            long long diff = req - sum2;
            for(int i=0;i<m;i++){
                if(mp.count(b[i]+diff)) return true;
            }
        }
        return -1;
	}
};

Input: N = 6, M = 4
A[] = {4, 1, 2, 1, 1, 2}
B[] = (3, 6, 3, 3)
Output: 1
Explanation: Sum of elements in A[] = 11
Sum of elements in B[] = 15, To get same 
sum from both arrays, we can swap following 
values: 1 from A[] and 3 from B[]
