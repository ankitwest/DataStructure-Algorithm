queue<int> modifyQueue(queue<int> q, int k) {
    stack<int>st;
    // if (q.empty() == true or k > q.size())
    //     return q;
    // if (k <= 0)
    //     return q;
        
    int k1 = k;
    while(k1--){
        st.push(q.front());
        q.pop();
    }
    
    /* Enqueue the contents of stack
       at the back of the queue*/
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }
 
    /* Remove the remaining elements and
       enqueue them at the end of the Queue*/
    for (int i = 0; i < q.size() - k; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}
