

// 153. Find Minimum in Rotated Sorted Array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==1)  // base case for n=1 element
            return nums[0];
        if(nums[0]<nums[n-1]) // base case for sorted array
            return nums[0];
        
        int l = 0; int h = n-1; 
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]>nums[mid+1])  //check condition
                return nums[mid+1];
            if(nums[l]<=nums[mid])   // found the sorted part , but minimum value lies in other half (right side)
                l = mid+1;
            else       // minimum value lies in other half (left side)
                h = mid-1;
        }
        return 0;
    }
};




// 33. Search in Rotated Sorted Arra



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

    
    //81. Search in Rotated Sorted Array II
    
    class Solution {
public:
    bool search(vector<int>& A, int key) {
        int  n = A.size();
        int l=0;int h = n-1; 
        while(l<=h){
            int mid = (l+h)/2;
            if(A[mid]==key)
                return true;
            if(A[l]==A[mid] and A[mid]==A[h])
                {l++,h--;continue;}
            
            if(A[l]<=A[mid]){
                if(A[l]<=key and key<A[mid])
                    h = mid-1;
                else 
                    l = mid+1;
            }else if(A[mid]<=A[h]){
                if(A[mid]<key and key<=A[h])
                    l = mid+1;
                else 
                    h = mid-1;
            }
        }
        return false;
    }
};
Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
[1,0,1,1,1]
0
false
