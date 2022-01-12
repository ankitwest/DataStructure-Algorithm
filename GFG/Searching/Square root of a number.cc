Input:
x = 5
Output: 2
Explanation: Since, 5 is not a perfect 
square, floor of square_root of 5 is 2.

class Solution{
  public:
  long long int BS(long long int num){
      long long int start , end, mid;
      long long int ans = -1;
      long long int sq;
      start = 0; end = num;
      while(start<=end){
          mid = start + (end-start)/2;
          sq = mid*mid;
          
          if(sq==num) 
            return mid;
          else if(sq<num){
              ans = mid;
              start = mid+1;
          }else if(sq>num){
              end = mid -1;
          }
      }
      return ans;
  }
    long long int floorSqrt(long long int x) 
    {
      return BS(x);
    }
};
