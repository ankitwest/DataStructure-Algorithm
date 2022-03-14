class Solution{
public:
    int biGraph(int arr[], int n, int e) {
      if(n==2 and e==1) return 1;
      
      int degree[n];
      memset(degree,0,sizeof(degree));
      
      for(int i=0;i<2*e;i+=2){
          degree[arr[i]]++;
          degree[arr[i+1]]++;
      }
      for(x:degree)
        if(x<2) return 0;
    
    return 1;
    }
    };
