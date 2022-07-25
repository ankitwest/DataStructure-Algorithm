class Solution{
public:
int *findTwoElement(int *arr, int n) {
        int xorr=0;
        for(int i=0;i<n;i++){
            xorr ^= arr[i];
            xorr ^= (i+1);
        }

        int lastBit =0;
        for(int k=0;k<32;k++){
            if(xorr&(1<<k)){
                lastBit = k;
                break;
            }
        }
         
        int first=0; int second=0;
        for(int i=0;i<n;i++){  
        
            // with array elements
            if(arr[i]&(1<<lastBit))   // w.r.t msb of xorr
                first ^= arr[i];    //if arr[i] bit is set put it in bucket a
            else
                second ^= arr[i];   //if arr[i] bit is not set put it in bucket b
            
            // with number elements 
            if((i+1)&(1<<lastBit)) 
                first ^= (i+1);   //if num bit is set put it in bucket a
            else
                second ^= (i+1);  //if num bit is not set put it in bucket b
        }
        
        int *a = new int[2];
        a[0] = first;
        a[1] = second;
        
        // make sure order of answer is crt
        int f = -1;
        for(int i=0;i<n;i++){
            if(a[0]==arr[i]) {
                 f=1;  
                 break;
            }
        }
        if(f==-1)  swap(a[0],a[1]);

        return a;
    }
};

//one more method 
// S sum of n ele
// S^2 sum of sq of ele
// and use math
  
class Solution2 {
public:      
    int *findTwoElement(int *arr, int n) {
        int *ans = new int[2];
        
        for(int i=0;i<n;i++){
            int pos = abs(arr[i])-1;
            if(arr[pos]<0)
                ans[0] = pos+1;
            else 
                arr[pos] *= -1;
        }
        
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                ans[1]=i+1;
                break;
            }
        }
        return ans;
    }
}:
