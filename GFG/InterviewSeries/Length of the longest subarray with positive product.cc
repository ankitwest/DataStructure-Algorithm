class Solution{
public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> arr,int n){
            int pos=0,neg=0,ans=0;
           for(int i=0;i<n;i++){
               if(arr[i]==0) pos=0,neg=0;
               else if(arr[i]>0) {
                   pos+=1;
                   if(neg!=0) neg+=1;
                   ans = max(ans,pos);
               }else if(arr[i]<0){
                   swap(pos,neg);
                   neg+=1;
                   if(pos!=0) pos+=1;
                   ans = max(ans,pos);
               }
           }
           return ans;
        }
};
