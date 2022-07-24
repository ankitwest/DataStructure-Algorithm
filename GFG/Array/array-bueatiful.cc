class Solution{
public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int> st; int n = arr.size();

        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(arr[i]);
                continue;
            }
            int x = st.top();
            if(x>=0 and arr[i]<0) 
                st.pop();
            else if(x<0 and arr[i]>=0) 
                st.pop();
            else 
                st.push(arr[i]);
        }
    
        vector<int> ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    };

Input: 4 2 -2 1
Output: 4 1
Explanation: As at indices 1 and 2 , 2 and -2 have
different sign, they are removed. And the  the final
array is: 4 1.

Input: 2 -2 1 -1
Output: []
Explanation: As at indices 0 and 1, 2 and -2 have
different sign, so they are removed. Now the array
is 1 -1.Now 1 and -1 are also removed as they have
different sign. So the final array is empty
