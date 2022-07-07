
Palindromic array   
Compress the array
Queries on matrix  

class Solution{
    public:
    bool palindromicArray(vector<int>& a, int n,int k){
        int i=0;int j=n-1;
        while(i<=j){
            if(a[i]!=a[j]){
                if(a[i]==k) i++;
                else if(a[j]==k) j--;
                else return 0;
            }else{
                i++;j--;
            }
        }
        return 1;
    }
};

Input: a[]={1,2,3,2,3,2,1,3}, K = 3
Output: Yes
Explanation: One can remove only the last element,
i.e. 3 equals to K to make the array palindrome






//del < hel

//del + x >= hel

class Solution{
  public:
  int compressArray(vector<int>& a, int n,int x){
     sort(a.begin(),a.end());
     
     int ans=0;
     for(int i=0;i<n;){
         int ind = i;
         while(ind<n and a[ind]==a[i]) {
             ind++;
         }
        int cnt = ind-i;
        if(ind==n or a[i] + x < a[ind]){
            ans += cnt;
        }
        i = ind;
     }
     return ans;
  }
};

a[i] > a[j] 
a[i] <= a[j] + X


Input: a[] = {1,2,3}, X = 1
Output: 1
Explanation:
Bob 1st remove 1, with the help of 2
2 > 1 and 2<=1+1.
Same way Bob removes 2 with heklp of 3.
So final answer will be 1.
