1310. XOR Queries of a Subarray



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



Input: arr = [1,3,4,8], queries = [[0,1],[1,2],[0,3],[3,3]]
Output: [2,7,14,8] 
Explanation: 
The binary representation of the elements in the array are:
1 = 0001 
3 = 0011 
4 = 0100 
8 = 1000 
The XOR values for queries are:
[0,1] = 1 xor 3 = 2 
[1,2] = 3 xor 4 = 7 
[0,3] = 1 xor 3 xor 4 xor 8 = 14 
[3,3] = 8
