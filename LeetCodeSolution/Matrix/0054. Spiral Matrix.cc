class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int n = a.size(); int m = a[0].size();
        int top=0;int bottom=n-1;
        int left=0;int right=m-1;
        
        vector<int> v; int dir=1;
        while(left<=right and top<=bottom){
            if(dir==1){
                for(int i=left;i<=right;i++) v.push_back(a[top][i]);
                dir=2,top++;
            }else if(dir==2){
                for(int i=top;i<=bottom;i++) v.push_back(a[i][right]);
                dir=3,right--;
            }else if(dir==3){
                for(int i=right;i>=left;i--) v.push_back(a[bottom][i]);
                dir=4,bottom--;
            }else if(dir==4){
                for(int i=bottom;i>=top;i--) v.push_back(a[i][left]);
                dir=1,left++;
            }
        }
        return v;
    }
};
