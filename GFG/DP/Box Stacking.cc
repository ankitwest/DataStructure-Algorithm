// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    struct box{
        int h,w,l;
    };
    int maxHeight(int height[],int width[],int length[],int n)
    {
         //STEP-1:Make an array of box (to store-> h,w,l)
      int len = 3*n;
      box arr[len];  //store  all 3 orientations
      int index = 0;
      for(int i=0;i<n;i++){
          arr[index].h = height[i];
          arr[index].w = max(width[i],length[i]);
          arr[index].l = min(width[i],length[i]);
          index++;
           
          arr[index].h = width[i];
          arr[index].w = max(height[i],length[i]);
          arr[index].l = min(height[i],length[i]);
          index++;
           
          arr[index].h = length[i];
          arr[index].w = max(width[i],height[i]);
          arr[index].l = min(width[i],height[i]);
          index++;
      }
       
       //STEP-2: Sort in DSC order of height
      sort(arr,arr+len,[&](struct box &a,struct box &b){
          return a.w*a.l > b.w*b.l;
      });
       
       //STEP-3: Find LIS
      int lis[len];
      for(int i=0;i<len;i++){
          lis[i] = arr[i].h;
      }
      
      for(int i=0;i<len;i++){
          for(int j=0;j<i;j++){
              if((arr[j].w > arr[i].w) and (arr[j].l > arr[i].l) and (lis[j] + arr[i].h > lis[i]))
                    lis[i] = lis[j] + arr[i].h;
          }
      }
       
      int maxi = 0;
      for(int i=0;i<len;i++)
            maxi = max(maxi,lis[i]);
            
        return maxi;
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int n;
        cin>>n;
        
    
        int A[105],B[105],C[105];
        for(int i = 0; i < n; i++)cin >> A[i];
        for(int j = 0; j < n; j++)cin >> B[j];
        for(int k = 0; k < n; k++)cin >> C[k];
        Solution ob;
        cout<<ob.maxHeight(A,B,C,n)<<endl;
    }
	
	return 0;
}
	  // } Driver Code Ends
