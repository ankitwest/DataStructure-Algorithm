
class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n = arr.size();
       vector<int> nle(n,-1),ple(n,-1);
       
       stack<int> st;
      for(int i=0;i<n;i++){
           while(!st.empty() and arr[st.top()]>arr[i]){
              ple[st.top()] = i;
               st.pop();
           }
           st.push(i);
       }
       while(!st.empty())
            st.pop();
            
        for(int i=n-1;i>=0;i--){
           while(!st.empty() and arr[st.top()]>arr[i]){
              nle[st.top()] = i;
               st.pop();
           }
           st.push(i);
       }
       
       vector<int>ans(n,-1);
       for(int i=0;i<n;i++){
           if(nle[i]==-1 and ple[i]==-1) ans[i] = -1;
           else if(nle[i]==-1)  ans[i] = ple[i];
           else if(ple[i]==-1)  ans[i] = nle[i];
           else{
                 if((ple[i]-i)<(i-nle[i]))
                    ans[i] = ple[i];
                else if((ple[i]-i)>(i-nle[i]))
                    ans[i] = nle[i];
                else if((ple[i]-i)==(i-nle[i])){
                    if(arr[ple[i]]<arr[nle[i]]) 
                        ans[i] = ple[i];
                    else 
                        ans[i] = nle[i];
                }
           }
       }
       return ans;
    }
    };
Input: 4 8 6 5 3
Output: 4 0 3 4 -1
  https://practice.geeksforgeeks.org/contest/interview-series-atlassian-4644/problems/#
