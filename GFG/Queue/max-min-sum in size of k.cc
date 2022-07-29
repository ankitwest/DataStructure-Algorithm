public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        deque<int> min_dq, max_dq;
        
        int i = 0;
        for(; i < k - 1; ++i) {
            while(!max_dq.empty() && arr[max_dq.back()] <= arr[i]) {
                max_dq.pop_back();
            }
            max_dq.push_back(i);
            
            while(!min_dq.empty() && arr[min_dq.back()] >= arr[i]) {
                min_dq.pop_back();
            }
            min_dq.push_back(i);
        }
        
        vector<int> ans;
        for(; i < n; ++i) {
            if(!max_dq.empty() && i - max_dq.front() == k) {
                max_dq.pop_front();
            }
            while(!max_dq.empty() && arr[max_dq.back()] <= arr[i]) {
                max_dq.pop_back();
            }
            max_dq.push_back(i);
            
            if(!min_dq.empty() && i - min_dq.front() == k) {
                min_dq.pop_front();
            }
            while(!min_dq.empty() && arr[min_dq.back()] >= arr[i]) {
                min_dq.pop_back();
            }
            min_dq.push_back(i);
            
            ans.push_back(arr[max_dq.front()] + arr[min_dq.front()]);
        }
        
        return ans;
    }
