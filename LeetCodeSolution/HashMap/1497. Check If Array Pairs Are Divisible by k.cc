class Solution {
public:
    bool canArrange(vector<int>& nums, int k) {
        int n = nums.size();
        // if(n&1) return false;
        
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            nums[i] = (nums[i]%k + k)%k;
            m[nums[i]]++;
        }
        if(m[0]&1) return false;
        
        for(int rem=1;rem<k;rem++){
            if(m[rem]!=m[k-rem]) return false;
        }
        
        return true;
    }
};



//more cases
// class Solution1 {
// public:
//     bool canArrange(vector<int>& nums, int k) {
//         unordered_map<int,int> m;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             int rem = (nums[i]%k + k)%k;  // for -ve values
//             m[rem]++;
//         }
//          for(int i=0;i<n;i++){  
//               int rem = nums[i] % k;
//             if(rem==0){
//                 if(m[rem]&1) return false;
//             }
//             else if(rem==k-rem){ 
//                 if(m[rem]&1) return false;
//             }
//             else if(m[rem] != m[k - rem])
//                 return false;
//         }
//         return true;
//     }
// };


