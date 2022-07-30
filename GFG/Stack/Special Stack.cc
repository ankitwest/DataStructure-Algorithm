void push(stack<int>& s, int a){
    if(!s.empty()){
        int tp = s.top();
        int bit = (1 << 16) - 1;
        int mini = tp & bit;
        mini = min(mini , a);
        a = (a << 16);
        a = a | mini;
        s.push(a);
        return ;
    }
    int newa = (a << 16);
    newa = newa | a;
    s.push(newa);
}

bool isFull(stack<int>& s,int n){
	return s.size() == n;
}

bool isEmpty(stack<int>& s){
	return s.size() == 0;
}

int pop(stack<int>& s){
	int tp = s.top(); 
	s.pop();
	tp = (tp >> 16);
	return tp;
}

int getMin(stack<int>& s){
	int tp = s.top();
// 	cout<<tp<<" ";
	int bit = (1 << 16) - 1;
	int mini = (tp & bit);
// 	cout<<mini<<" ";
// 	cout<<bit<<" ";
	return mini;
}
