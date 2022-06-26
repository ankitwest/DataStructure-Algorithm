class Solution{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        unordered_map<int,int> m;
        unordered_set<int> s(arr,arr+n);
        int k = s.size();   
        
        int i=0,l=0;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            while(l<=i and m.size()>=k){
                ans += (n-i);
                m[arr[l]]--;
                if(m[arr[l]]==0) m.erase(arr[l]);
                l++;
            }
        }
        return ans;
    }
    };


Input:
N=5
arr[] = {2, 1, 3, 2, 3} 
Output: 5
Explanation:
Total distinct elements in array is 3
Total sub-arrays that satisfy the condition
are:
Subarray from index 0 to 2
Subarray from index 0 to 3
Subarray from index 0 to 4
Subarray from index 1 to 3
Subarray from index 1 to 4
