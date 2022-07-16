class Solution{
public:
    int gameOfXor(int N , int A[]) {
        int ans = 0;
        for(int i=0;i<N;i++){
            int freq = (i+1)*(N-i);
            if(freq&1)
            ans = ans ^ A[i];
        }
        return ans;
    }
};


Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)
