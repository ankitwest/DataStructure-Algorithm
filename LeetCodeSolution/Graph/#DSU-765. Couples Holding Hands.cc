
// O(N^2)
class Solution {
public:
    
    int minSwapsCouples(vector<int>& arr) {
        int n = arr.size(); 
        int ctr=0;
        for(auto &x:arr) x /= 2;
        
        for(int i=0;i<n-1;i+=2){
            if(arr[i]==arr[i+1]) continue;
            else{
                for(int j=i+2;j<n;j++)
                    if(arr[i]==arr[j]) {swap(arr[i+1],arr[j]); break;}
                ctr++;
            }
        }
        return ctr;
    }
};


Example 1:

Input: row = [0,2,1,3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
Example 2:

Input: row = [3,2,0,1]
Output: 0
Explanation: All couples are already seated side by side.
  
  
  
  DSU
  
  class DSU{
     vector<int> parent;
    public:
    DSU(int n){
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    void set_par(int x,int p){
        parent[x] = p;
    }
    int find_par(int x){
        if(x!=parent[x])
            parent[x] = find_par(parent[x]);
        return parent[x];
    }
    bool UNION(int u,int v){
        int pu = find_par(u);
        int pv = find_par(v);
        
        parent[pu] = pv;
        return pu==pv;
    }
};

class Solution {
public:
    //M-1  O(N^2)
    //M-2  DSU
    int minSwapsCouples(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return 0;
        
        DSU uf(n);
        
        for(int i=0;i<n;i+=2){
            uf.set_par(arr[i],arr[i]);
            uf.set_par(arr[i+1],arr[i]);
        }
        
        int swp=0;
        for(int i=0;i<n;i+=2){
            if(uf.UNION(i,i+1)==false)
                swp++;
        }
        return swp;
    }
};
