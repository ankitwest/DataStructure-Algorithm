
long long int calculate1(int arr[], int n)
{
    map<int,int> m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    int ans=0;
    for(auto x:m){
        int y = x.second;
        ans += (y)*(y-1)/2;
    }
     return ans;
}
long long int calculate(int arr[], int n)
{
    map<int,int> m;
    int ans=0;
    for(int i=0;i<n;i++){
        if(m.find(arr[i])!=m.end()){
            ans += m[arr[i]];
        }
            m[arr[i]]++;
    }
    return ans;
}

Input : arr[ ] = {2, 2, 2} 
Output :  3
