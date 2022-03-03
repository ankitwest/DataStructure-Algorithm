// not important

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            int a=l[i],b=r[i]; 
            
            vector<int> v;
            for(int j=a;j<=b;j++){
                v.push_back(nums[j]);
            }
            
            sort(v.begin(),v.end());
            int diff=0;
            set<int>s;
            for(int k=1;k<v.size();k++){
                diff=v[k]-v[k-1];
                s.insert(diff);
            }
            if(s.size()==1) ans.push_back(true); else ans.push_back(false);
        }
        return ans;
    }
};

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
