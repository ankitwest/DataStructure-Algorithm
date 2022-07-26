

vector<int> addOne(int a[], int n) {
        int carry = 1;
       reverse(a,a+n);
       vector<int> ans;
        for(int i=0;i<n;i++)
         {
             if(a[i]+carry>9){
                  ans.push_back((a[i]+carry)%10);
                  carry = (a[i]+carry)/10;
             }else{
                   ans.push_back((a[i]+carry));
                   carry=0;
               }
         }
         
        //  maximum carry can be 1
        if(carry) ans.push_back(1);
   
       reverse(ans.begin(),ans.end());
      
    return ans;
    }
    
    Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)





    
    
    
    vector<int> increment(vector<int> digits ,int n) {
    reverse(digits.begin(),digits.end());

    int carry = 1;
    for(int i=0;i<n;i++)
    {
        if(carry!=0)
            digits[i]+=carry;
        // Now to get carry
        carry = digits[i]/10;
        
        // Now if carry is not equal to 0 ,val in 2 digits
        if(carry!=0)
            digits[i] = digits[i]%10;
    }

    if(carry==1)
        digits.push_back(carry);

    reverse(digits.begin(),digits.end());
     return digits;
    
    }
    
    Expected Time Complexity:  O(N)
Expected Auxilliary Space: O(1)
