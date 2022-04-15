

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
         int n = mat.size(); int m = mat[0].size(); 
         // we are looking for such index which could yield me a height less than the current one 
        auto maxAreaInHistogram = [&](vector<int> &heights)->int{
            int l = heights.size(); 
            stack<int> st;
            vector<int> left(l,0),right(l,0);
            
            for(int i=0;i<l;i++){
                while(!st.empty() and heights[st.top()]>=heights[i]) 
                    st.pop();
                if(st.empty()) left[i]=0;
                else left[i]=st.top()+1;
                st.push(i);
            }
        
            while(!st.empty()) st.pop();

            for(int i=l-1;i>=0;i--){
                while(!st.empty() and heights[st.top()]>=heights[i])
                    st.pop();
                if(st.empty()) right[i]=l-1;
                else right[i]=st.top()-1;
                st.push(i);
            }
            
            int area=0;
            for(int i=0;i<l;i++){
                area = max(area,heights[i]*(right[i]-left[i]+1));
            }
            return area;
        };
        
        int max_area = 0;
        vector<int> v(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='0') v[j]=0;
                else v[j] = v[j] + (mat[i][j]-'0');
            }
            int area = maxAreaInHistogram(v);
            max_area = max(max_area,area);
        }
        return max_area;
    }
};

