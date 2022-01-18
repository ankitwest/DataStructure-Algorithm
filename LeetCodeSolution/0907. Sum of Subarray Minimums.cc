class Solution {
public:
    const int MOD = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();

    stack<int> st;
    vector<int> left(n),right(n);

    for(int i=0;i<n;i++){
        while(!st.empty() and arr[st.top()] > arr[i])
            st.pop();
        if(st.empty()) left[i] = i+1;   //0
        else left[i] = i-st.top();      //st.top()+1

        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i=n-1;i>=0;i--){
        while(!st.empty() and arr[st.top()] >= arr[i])
            st.pop();
        if(st.empty()) right[i] = n-i;  //n-1
        else right[i] = st.top()-i;    //st.top()-1

        st.push(i);
    }
        //  for(int i=0; i<n; i++) cout << left[i] << " : " << right[i] << endl;
        // cout<<endl;
      
    long long sum = 0 , noOfSubarray = 1 , contri = 1;
    for(int i=0;i<n;i++){
        noOfSubarray = (left[i]*right[i])%MOD;
        contri = (noOfSubarray*arr[i])%MOD;
        sum = (sum+contri)%MOD;
    }

    return sum%MOD;
    }
};


Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 

Example 1:

Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:

Input: arr = [11,81,94,43,3]
Output: 444

    
    // Simpler form
    
    int n=nums.size();
        long long sum=0;
        stack<int>st;
        vector<int> minPrev(n,-1),minNext(n,n);
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&nums[st.top()]>=nums[i]){st.pop();}
            if(!st.empty()){minPrev[i]=st.top();}
            st.push(i);
        }
        while(!st.empty()){st.pop();}
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&nums[st.top()]>nums[i]){st.pop();}
            if(!st.empty()){minNext[i]=st.top();}
            st.push(i);
        }

         for(int i=0;i<n;i++)
        {
            long long leftMin=i-minPrev[i],rightMin=minNext[i]-i;
            sum+=(leftMax*rightMaxx)*nums[i];
            
        }
        return sum;
    
