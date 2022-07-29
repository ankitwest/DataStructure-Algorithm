deque<int> dq;
        
        int i = 0;
        while(i < k - 1) {
            while(!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            dq.push_back(i++);
        }
        
        vector<int> ans;
        for(; i < n; ++i) {
            if(!dq.empty() && i - dq.front() == k) {
                dq.pop_front();
            }
            
            while(!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            ans.push_back(arr[dq.front()]);
        }
        
        return ans;
