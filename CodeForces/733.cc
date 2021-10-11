//Div 2


void solveB(){
   int n,m;cin>>n>>m;
   vector<vector<int>> arr(n,vector<int>(m,0));
   vector<vector<int>> arr2(n,vector<int>(m,0));

   int dirX[] = {-1, 0, 1, 0, -1, -1, 1, 1};
   int dirY[] = {0, -1, 0, 1, -1, 1, -1, 1};
   rep(i,0,n){
         rep(j,0,m){
            if(i==0 or i==n-1 or j==0 or j==m-1){
            bool f=true;
               rep(k,0,8){
                  int nx = i+dirX[k];
                  int ny = j+dirY[k];
                  if(nx<0 or ny<0 or nx>n-1 or ny>m-1) continue;
                  if(arr2[nx][ny]==1) {f=false; break;}
               }
               if(f) arr2[i][j]=1;
            }
            
         }
      }

   int h=n,w=m;
    for(int j=0;j<w;j++){
      if(j%2==0){
         arr[0][j]=1;
         arr[h-1][j]=1;
      }
   }
   for(int i=2;i<=h-3;i++){
      if(i%2==0){
         arr[i][0]=1;
         arr[i][w-1]=1;
      }
   }
  
       rep(i,0,n){
         rep(j,0,m){
            cout<<arr[i][j];
         }ln;
      }ln;

}
