class Solution{
public:
	bool recreationalSpot(int arr[], int n){
		if(n<3) return false;
		int preMin[n];
		preMin[0]=arr[0];
		for(int i=1;i<n;i++){
		    preMin[i] = min(preMin[i-1], arr[i]);
		}
		
		stack<int> st;
		for(int i=n-1;i>=0;i--){
		    if(preMin[i]<arr[i]){
		        while(!st.empty() and st.top()<=preMin[i]){
		            st.pop();
		        }
		        if(!st.empty() and st.top()<arr[i])
		            return true;
		    }
		     st.push(arr[i]);
		}
		
		return false;
	}
};
Input:
N = 6
arr[] = {4, 7, 11, 5, 13, 2}
Output:
True
Explanation:
[4, 7, 5] fits the condition.
