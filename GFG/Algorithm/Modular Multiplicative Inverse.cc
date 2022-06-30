   public:
    //Complete this function
    int modInverse(int a, int m)
    {
        for(int i=1;i<m;i++){
            int x = i;
            if( ((a%m) * (x%m)) %m == 1)
                return x;
        }
        return -1;
    }

TC - O(M)
  
  
  
  MMI
  a x ≅ 1 (mod m)
The value of x should be in { 1, 2, … m-1}, i.e., in the range of integer modulo m. ( Note that x cannot be 0 as a*0 mod m will never be 1 ) The multiplicative inverse of “a modulo m” exists if and only if a and m are relatively prime (i.e., if gcd(a, m) = 1).

Method 1 (Naive) 
A Naive method is to try all numbers from 1 to m. For every number x, check if (a*x)%m is 1. 
Time Complexity: O(m)

Method 2 ( Works when m and a are coprime or gcd(a,m)=1 ) 
The idea is to use Extended Euclidean algorithms that takes two integers ‘a’ and ‘b’, finds their gcd and also find ‘x’ and ‘y’ such that 
ax + by = gcd(a, b)
ax + my = 1    [b = m]
ax  ≅ 1 (mod m)
Time Complexity: O(log m)


Method 3 (Works when m is prime) 
If we know m is prime, then we can also use Fermats’s little theorem to find the inverse. 
a^m-1 ≅ 1 (mod m)
If we multiply both sides with a^-1, we get 
a^-1 ≅ a^m-2 (mod m)
Time Complexity: O(log m)
