Input to count the number of set bits from 1 to n

class Solution{
    public:
    int solve(int n){
        if(n==0) return 0;
        int x = floor(log2(n));
        int powerof2 = pow(2,x)/2*x;  // (1<<(x-1))*x;
        int count = n-pow(2,x)+1;  // n-1<<x+1;
        int rest = n-pow(2,x);   //n-(1<<x);
        int ans = powerof2+count+solve(rest);
        return ans;
    }
    int countSetBits(int n)
    {
        return solve(n);
    }
};

0 - 0000
1 - 0001
2 - 0010
3 - 0011
4 - 0100
