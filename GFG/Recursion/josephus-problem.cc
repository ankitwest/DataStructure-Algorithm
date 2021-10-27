class Solution{
 public:
    int josephus(int n, int k)
    {
      if(n==1) return 1;
      else return (josephus(n-1,k)+k-1)%n+1;
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


