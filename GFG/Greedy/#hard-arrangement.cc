static bool compare(vector<int> v1,vector<int> v2){
    if(v1[0]==v2[0]) return v1[1]<v2[1];
    return v1[0]>v2[0];
}
vector<int> arrange(vector<int> &A, vector<int> &B, int n) {
   
   vector<vector<int>> people(n);
   for(int i=0;i<n;i++){
       people[i].push_back(A[i]);
       people[i].push_back(B[i]);
   }
    
    sort(people.begin(),people.end(),compare);
    
    vector<int> ans;
    for(int i=0;i<people.size();i++){
        // auto pos = ans.begin() + v[1];
        // ans.insert(pos,v[0]);
        // cout<<people[i][1]<<" ";
        ans.insert(ans.begin() + people[i][1],people[i][0]);
    }
    return ans;
};


height ,pos
4,0 4,1 5,2
