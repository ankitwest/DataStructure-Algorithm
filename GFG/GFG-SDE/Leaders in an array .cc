class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int arr[], int n){
        vector<int> v; int maxi = arr[n-1];
        
        for(int i=n-1;i>=0;i--){
            if(arr[i]>=maxi)
                v.push_back(arr[i]);
                
            maxi = max(maxi,arr[i]);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};


Input:
n = 6
A[] = {16,17,4,3,5,2}
Output: 17 5 2
Explanation: The first leader is 17 
as it is greater than all the elements
to its right.  Similarly, the next 
leader is 5. The right most element 
is always a leader so it is also 
included.
