// window sliding technique

class Solution{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> v;
        multiset<int,greater<int>> s;
        for(int i=0;i<n;i++){
            s.insert(arr[i]);
            if(s.size()>k){
                s.erase(s.find(arr[i-k]));
            }
            if(s.size()==k){
                v.push_back(*s.begin());
            }
        }
        return v;
    }
};
O(NlogN)

class Solution{
public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
       vector<int> ans;
       deque<int>dq;
       for(int i=0;i<n;i++){
          if(!dq.empty() and dq.front()==i-k) dq.pop_front(); //out of bound
          while(!dq.empty() and arr[dq.back()]<=arr[i]) dq.pop_back();
          dq.push_back(i);
          if(i+1>=k) ans.push_back(arr[dq.front()]);
       }
       return ans;
    }
};

O(N)
