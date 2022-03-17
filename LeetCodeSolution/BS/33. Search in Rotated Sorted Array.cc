class Solution {
public:
    int search(vector<int>& A, int key) {
        int  n = A.size();
        int l=0;int h = n-1; 
        while(l<=h){
            int mid = (l+h)/2;
            if(A[mid]==key)
                return mid;
            else if(A[l]<=A[mid]){
                if(A[l]<=key and key<=A[mid])
                    h = mid-1;
                else 
                    l = mid+1;
            }else if(A[mid]<=A[h]){
                if(A[mid]<=key and key<=A[h])
                    l = mid+1;
                else 
                    h = mid-1;
            }
        }
        return -1;
    }
};

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
