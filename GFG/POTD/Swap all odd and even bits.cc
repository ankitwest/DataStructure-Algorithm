class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
        int ans =0;
        for(int i=0;i<32;i+=2){
            int r = (1<<(i))&n;  r <<=1;
            ans += r;
            int l= (1<<(i+1))&n; l >>=1;
            ans += l;
        }
    	return ans;
    	
    	
    }
};





class Solution
{
    public:
    //Function to swap odd and even bits.
    unsigned int swapBits(unsigned int n)
    {
        int a=1,b=0; int sum=0;
    	while(n){
    	    int rem1=n%2;n/=2;
    	    int rem2=n%2;n/=2;
    	    sum+=rem1*pow(2,a);
    	    sum+=rem2*pow(2,b);
    	    a+=2;b+=2;
    	}
    	return sum;
    	
    	
    }
};
