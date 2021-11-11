class Solution{
public:
 vector<int> candyStore(int candies[], int N, int K)
   {
       int mini=0,maxi=0;
       int i=0;int j=N-1;
       int n = N;
       sort(candies,candies+N);
       while(i<n){
           mini+=candies[i];
           n-=K;
           i++;
       }
      i=0;
      while(j>=i){
          maxi+=candies[j];
          i+=K;
          j--;
      }
 
       return {mini,maxi};
   }
};
