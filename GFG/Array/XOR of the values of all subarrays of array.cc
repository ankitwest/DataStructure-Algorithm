Game of XOR 

int gameOfXor(int n , int arr[]) {
        int xorr=0;
        for(int i=0;i<n;i++){
            int contri=(i+1)*(n-i);
            if(contri%2==1)
                xorr^=arr[i];
        }
        return xorr;
    }



Input: N = 3, A[] = {1,2,3} 
Output: 2
Explanation:
xor[1] = 1, 
xor[1, 2] = 3
xor[2, 3] = 1
xor[1, 2, 3] = 0
xor[2] = 2
xor[3] = 3
Result : 1 ^ 3 ^ 1 ^ 0 ^ 2 ^ 3 = 2
