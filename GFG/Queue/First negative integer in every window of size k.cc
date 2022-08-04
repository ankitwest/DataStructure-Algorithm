vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int n, long long int k) {
    deque<int> dq;
    for(int i = 0; i < k - 1; ++i) {
        if(a[i] < 0) {
            dq.push_back(i);
        }
    }
    
    vector<long long> ans;
    for(int i = k - 1; i < n; ++i) {
        while(!dq.empty() && i - dq.front() >= k) {
            dq.pop_front();
        }
        
        if(a[i] < 0) {
            dq.push_back(i);
        }
        
        int val = 0;
        if(!dq.empty()) {
            val = a[dq.front()];
        }
        ans.push_back(val);
    }
    
    return ans;
 }
 
vector<long long> printFirstNegativeInteger(long long int a[],
                                             long long int n, long long int k) {
    int f_n = -1;
    for(int i = k - 2; i >= 0; --i) {
        if(a[i] < 0) {
            f_n = i;
        }
    }
    
    vector<long long> ans;
    for(int i = k - 1; i < n; ++i) {
        while(i - f_n >= k) {
            ++f_n;
        }
        
        while(a[f_n] > 0 && f_n <= i) {
            ++f_n;
        }
        
        if(f_n > i) {
            ans.push_back(0);
        } else {
            ans.push_back(a[f_n]);
        }
    }
    
    return ans;
 }
