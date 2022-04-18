

class Solution{
{
	public:
		long long int PowMod(long long int x,long long int p,long long int M)
		{
		    long long ans = 1;
		    
		   while(p){
		       if(p&1)
		            ans = (ans*x)%M;
		        p >>=1;
		        x = (x*x)%M;
		   }
		   return ans;
		}
    };
