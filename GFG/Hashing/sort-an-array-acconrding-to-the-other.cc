    // A1[] : the input array-1
    // N : size of the array A1[]
    // A2[] : the input array-2
    // M : size of the array A2[]
    
    //Function to sort an array according to the other array.
class Solution{
public:
    vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        map<int,int>m1;
       for(int i=0;i<N;i++){
           m1[A1[i]]++;
       }
       vector<int> v;
       for(int i=0;i<M;i++){
           int x = m1[A2[i]];
           if(x>0) {
               while(x--) 
                    v.push_back(A2[i]);
           }
           m1.erase(A2[i]);
       }

        for(auto x:m1)
            while(x.second--)
                v.push_back(x.first);
        
       return v;
    } 
};


Expected Time Complexity: O(N * Log(N)).
Expected Auxiliary Space: O(N).
  
  
  
  

class Solution{
public:
      vector<int> sortA1ByA2(vector<int> A1, int N, vector<int> A2, int M) 
    {
        unordered_map<int,int>m1;
       for(int i=0;i<N;i++){
           m1[A1[i]]++;
       }
       vector<int> v;
       for(int i=0;i<M;i++){
           int x = m1[A2[i]];
           if(x>0) {
               while(x--) 
                    v.push_back(A2[i]);
           }
           m1.erase(A2[i]);
       }
        int done = v.size();
        for(auto x:m1)
            while(x.second--)
                v.push_back(x.first);
                
        sort(v.begin()+done,v.end());
       return v;
    } 
};
