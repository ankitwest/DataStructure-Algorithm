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
                lastBit = k; break;
            }
        }
         
        int first=0; int second=0;
        for(int i=0;i<n;i++){
            if(arr[i]&(1<<lastBit))
                first ^= arr[i];
            else
                second ^= arr[i];
            
            // repeating element
            if((i+1)&(1<<lastBit))
                first ^= (i+1);
            else
                second ^= (i+1);
        }
        
        int *a = new int[2];
        a[0] = first;
        a[1] = second;
        int f=-1;
        for(int i=0;i<n;i++){
            if(a[0]==arr[i]) {
                 f=1;  break;
            }
        }
        if(f==-1)  swap(a[0],a[1]);

        return a;
    }
 };



Very nice will have to think
M-2
  Optimizing Space and Time
  
  int *findTwoElement(int *arr, int n) {
        int *ans = new int[2];
        for(int i=0;i<n;i++){
            int pos = abs(arr[i])-1;
            if(arr[pos]<0)
                ans[0]=pos+1;
            else 
                arr[pos] *=-1;
        }
        
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                ans[1]=i+1;
                break;
            }
        }
        return ans;
    }
  
