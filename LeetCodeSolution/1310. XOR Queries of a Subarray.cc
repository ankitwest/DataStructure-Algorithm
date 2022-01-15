class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> v;
        vector<int> x_arr(n);     x_arr[0]=arr[0];
        
        for(int i=1;i<n;i++){
            x_arr[i] = x_arr[i-1]^arr[i];
        }
        
        for(int i=0;i<queries.size();i++){
            int x = queries[i][0];
            int y = queries[i][1];
            
            if(x==0){
                v.push_back(x_arr[y]);
            }else if(x==y){
                v.push_back(arr[x]);
            }else{
                v.push_back(x_arr[y]^x_arr[x-1]);
            }
        }
        return v;
    }
};
