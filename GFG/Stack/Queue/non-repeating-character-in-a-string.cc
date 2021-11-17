class Solution{
  	public:
		string FirstNonRepeating(string A){
		    int arr[26]={0};
		    queue<char> q;
		    string ans; char ch;
		    for(int i=0;i<A.size();i++){
		        arr[A[i]-'a']++;
		        if(arr[A[i]-'a']==1) q.push(A[i]);
		        
		        while(!q.empty() and arr[q.front()-'a']!=1){
		            q.pop();
		        }
		        if(q.empty()) ch='#';
		        else ch=q.front();
		        ans += ch;
		    }
		    return ans;
		}
};
Input: A = "aabc"
Output: "a#bb"
  
      
Input: A = "zz"
Output: "z#"
