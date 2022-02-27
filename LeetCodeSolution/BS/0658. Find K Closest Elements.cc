class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //M-1
        stable_sort(arr.begin(),arr.end(),[x](const int a,const int b){
            return abs(a-x)<abs(b-x);
        });
        arr.resize(k);
        sort(arr.begin(),arr.end());
        return arr;
        
        //M-2
        int L = 0; int R = arr.size()-1;
        while(R - L >= k){
            if(x-arr[L]<=arr[R]-x) R--;
             else L++;
        }
        return vector<int>(arr.begin()+L,arr.begin()+R+1);
        
        //M-3  better
        int n = arr.size(); int R = lower_bound(arr.begin(),arr.end(),x)-arr.begin(); int L = R-1;
        while(k--){
            if((R>=n) or (L>=0 and x - arr[L] <= arr[R] - x)) L--;
            else R++;
        }
        return vector<int>(arr.begin()+L+1,arr.begin()+R);
    }
};

class Solution {
public:
   //M-4
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<arr.size();i++){
            pq.push({abs(arr[i]-x),arr[i]});
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};




Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
