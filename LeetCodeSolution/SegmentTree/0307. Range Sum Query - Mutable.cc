

class NumArray{
public:
    int n; 
    vector<int> seg; vector<int> arr;
    void buildTree(int ind,int low,int high){
       if(low==high){
            seg[ind]=arr[low];
            return ;
        }
        int mid = (low+high)/2;
        buildTree(2*ind+1,low,mid);
        buildTree(2*ind+2,mid+1,high);
        
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    int queryTree(int ind,int low,int high,int l,int r){
        if(l>high or r<low)   //no overlap
            return 0;
        if(l<=low and r>=high)  // complete overlap
            return seg[ind];
        
        int mid = (low+high)/2;    //partial overlap
        int left = queryTree(2*ind+1,low,mid,l,r);
        int right = queryTree(2*ind+2,mid+1,high,l,r);
        
        return left + right;
    }
    void updateTree(int ind,int low,int high,int pos,int val){
         if(pos<low or pos>high)   //no overlap
            return;
        
        if(low==high){
            seg[ind]=val;
            return;
        }
        int mid = (low+high)/2;
        updateTree(2*ind+1,low,mid,pos,val);
        updateTree(2*ind+2,mid+1,high,pos,val);
        
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
    }
    
    
    NumArray(vector<int>& nums) {
        n=nums.size(); arr = nums;
        seg.resize(4*n);
        buildTree(0,0,n-1);
    }
    void update(int pos, int val) {
        updateTree(0,0,n-1,pos,val);
    }
    int sumRange(int l, int r) {
        return queryTree(0,0,n-1,l,r);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
