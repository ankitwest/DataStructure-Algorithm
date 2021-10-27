class Solution{
      public:
    long long toh(int N, int from, int to, int aux) {
        if(N==0) return 0;

         int AB = toh(N-1,from,aux,to);
             cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        int BC = toh(N-1,aux,to,from);
        
        return 1+AB+BC;
        
    }
};



Expected Time Complexity: O(2N).
Expected Auxiliary Space: O(N).

