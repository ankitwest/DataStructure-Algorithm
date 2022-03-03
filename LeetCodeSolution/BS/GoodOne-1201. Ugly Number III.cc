class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
       long long low = 0, high = 2e9; long long ans = 0;
        
        auto lcm =[&](long long a,long long b){
            return a*b/__gcd(a,b);
        };
        auto count = [&](long long mid){
            int cnt=0;
            cnt += mid/a; cnt += mid/b; cnt += mid/c;
            cnt -= mid/lcm(a,b); cnt -= mid/lcm(b,c); cnt -= mid/lcm(a,c);
            cnt += mid/(lcm(a,lcm(b,c)));
            return cnt;
        };
        
        while(low<=high){
            long long mid = low+(high-low)/2;
            if(count(mid)>=n)
                ans = mid,high = mid-1;
            else 
                low = mid+1;
        }
        return ans;
    }
};
An ugly number is a positive integer that is divisible by a, b, or c.

Given four integers n, a, b, and c, return the nth ugly number.

 

Example 1:

Input: n = 3, a = 2, b = 3, c = 5
Output: 4
Explanation: The ugly numbers are 2, 3, 4, 5, 6, 8, 9, 10... The 3rd is 4.
Example 2:

Input: n = 4, a = 2, b = 3, c = 4
Output: 6
Explanation: The ugly numbers are 2, 3, 4, 6, 8, 9, 10, 12... The 4th is 6.
Example 3:

Input: n = 5, a = 2, b = 11, c = 13
Output: 10
Explanation: The ugly numbers are 2, 4, 6, 8, 10, 11, 12, 13... The 5th is 10.
