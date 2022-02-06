class Solution
{
    public:
    int n;
    //Function to find the largest number after k swaps.
    void klp(string &str,int k,string &res,int index){
        if(k==0) return;
        
        char maxi = str[index];
        for(int i=index+1;i<n;i++){
            if(str[i]>maxi)
                maxi=str[i];
        }
        
        if(maxi!=str[index])
            k--;
            
        for(int j=n-1;j>=index;j--){
            if(str[j]==maxi){
                swap(str[index],str[j]);
                if(str.compare(res)>0)  {res=str;}
              
                klp(str,k,res,index+1);
                swap(str[index],str[j]);
            }
        }
    }

    string findMaximumNum(string str, int k)
    {
        string res=""; n = str.size();
        klp(str,k,res,0);
      return res;
    }
    };
    
    Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the
input 1234567 to 7654321, swapping 1
with 7, 2 with 6 and finally 3 with 5
