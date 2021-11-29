class Solution {
  public:
    //no of subarrays with sum <=limit
    long long count(vector<int> &A,long long limit){
        long long i=0,j=0;
        long long sum=0,ans=0;
        while(j<A.size()){
            sum+=A[j];
            while(sum>limit) sum -= A[i++];
            ans += j-i+1;
            j++;
        }
        return ans;
    }
    long long countSubarray(int N,vector<int> A,long long L,long long R) {
        return count(A,R)-count(A,L-1);
    }
};
Expected Time Complexity: O(N)
