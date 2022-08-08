class Solution{
 public:
    int josephus(int n, int k)
    {
      if(n==1) return 0 + 1; //index
      else{
          int x = josephus(n-1,k);  //   int y = (x+k) % n;  
          int y = (x + (k - 1)) % n;
          return y + 1;  //index
      }
    }
    
    // direct
    int josephus2(int n, int k)
    {
      if(n==1) return 1;
      else return (josephus(n-1,k)+k-1) % n + 1;
    }
];



Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).











class Solution{
      public:
    int josephus(int n, int k)
    {
      queue<int>q;
      for(int i=1;i<=n;i++){
          q.push(i);
      }
      
      while(q.size()>1){
          for(int i=1;i<k;i++){
              q.push(q.front());
              q.pop();
          }
          q.pop();
      }
      
      return q.front();
    }
};


