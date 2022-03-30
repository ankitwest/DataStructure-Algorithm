
class Solution{
  public:
    int maxArea(int matrix[MAX][MAX], int n, int m) {
        vector<int> v(m,0);
        
        auto maxAreaHistogram = [&](vector<int>& arr,int n){
            stack<int> st;
            vector<int> left(n),right(n);
            for(int i=0;i<n;i++){
                while(!st.empty() and arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.empty()) left[i] = -1;
                else left[i] = st.top();
                st.push(i);
            }
            
             while(!st.empty()) st.pop();
            for(int i=n-1;i>=0;i--){
                while(!st.empty() and arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.empty()) right[i]=n;
                else right[i]=st.top();
                st.push(i);
            }
            
            int maxArea = -1;
            for(int i=0;i<n;i++){
                int width=right[i]-left[i]-1;
                int area=arr[i]*width;
                maxArea=max(maxArea,area);
            }
            return maxArea;
        };
        
        
        int ans = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) v[j]=0;
                else v[j] = v[j] + matrix[i][j];
            }
            int area = maxAreaHistogram(v,m);
             ans = max(ans, area);
        }
        return ans;
    }
};

