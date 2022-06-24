class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;
        
        m[nums[n-1]] = 1;
        int ans = 0;
        for (int i=n-2;i>=2;i--){
            for (int j=i-1;j>=1;j--){
                for (int k=j-1;k>=0;k--){
                    if (m.count(nums[i]+nums[j]+nums[k]))
                        ans += m[nums[i]+nums[j]+nums[k]];
                }
            }
            m[nums[i]] += 1;
        }
        return ans;
    }
};


class Solution2 {
public:  // TC - O(N^2)
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        
        unordered_map<int, int> m;
        for (int b=n-1;b>0;b--) {
            for (int a=b-1;a>=0;a--) {
                ans += m[nums[a] + nums[b]];
            }
            for (int x=n-1;x>b;x--) {
                m[nums[x]-nums[b]] +=1 ;
            }
        }
        return ans;
    }
};


// TC - O(N^3)
// By going backwards, we guarantee that d comes after a,b, and c, and for each combination of a,b, and c, we simply check the dictionary to see if we have already seen their sum before.



// a+b+c = d therefore b+a = d-c and since a plays the role of both c and a: b+a = d-(a*).

// https://leetcode.com/problems/count-special-quadruplets/discuss/1446988/JavaC%2B%2BPython3-Real-O(n2)-solution



