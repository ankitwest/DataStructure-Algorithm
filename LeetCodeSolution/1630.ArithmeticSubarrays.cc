class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
           if(r[i]-l[i]<2) ans.push_back(true);
            else{
                 vector<int> v(nums.begin()+l[i],nums.begin()+r[i]+1);
            
            sort(v.begin(),v.end());
            int diff=v[1]-v[0]; bool f=false;
            for(int k=2;k<v.size();k++){
                if(v[k]-v[k-1]!=diff){
                    f=true;break;
                }
            }
            ans.push_back(!f);
            }
        }
        return ans;
        
    }
        
};
