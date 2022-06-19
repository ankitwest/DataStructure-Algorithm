        vector<int> edge(n,0);
        for(int i=1;i<n;i++){
            edge[i]++;
            edge[p[i]]++;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(edge[i]==1) cnt++;
        }


N = 5
p[] = {-1, 0, 0, 1, 1}
Output:
1
Explanation: 
Tree looks like:
            0
           / \ 
         1    2 
       /  \ 
      3    4
Merge the edge 0 - 2 in one operation
