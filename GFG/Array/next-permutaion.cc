class Solution{
public:
    vector<int> nextPermutation(int n, vector<int> arr){
        if(n==1) return arr;
        
        int bottomInd = -1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){ 
                bottomInd = i; break;
            }
        }
        
        if(bottomInd==-1){  // decreasing order
            reverse(arr.begin(),arr.end());
            return arr;
        }
            
        int swapInd = bottomInd-1;
        for(int i=n-1;i>=0;i--){
            if(arr[i]>arr[bottomInd]){
                swapInd = i;
                break;
            }
        }  
        // if we dont find special one then normal one will store swapInd = bottomInd+1
        // cout<<swapInd<<" "<<bottomInd<<endl;
        swap(arr[bottomInd],arr[swapInd]);
        sort(arr.begin()+bottomInd+1,arr.end());
        return arr;
    }
};

Example 1:

Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}
Explaination: The next permutation of the 
given array is {1, 2, 4, 3, 5, 6}.
Example 2:

Input: N = 3
arr = {3, 2, 1}
Output: {1, 2, 3}
Explaination: As arr[] is the last 
permutation. So, the next permutation 
is the lowest one.
