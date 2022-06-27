class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int ans = INT_MIN;
        vector<int> col_sum(n, 0);
        
        for (int l = 0; l < m; l++)      
        {
            fill(col_sum.begin(), col_sum.end(), 0);
            for (int r = l; r < m; r++) 
            {
                for (int i = 0; i < n; i++) 
                    col_sum[i] += matrix[i][r];  
                
                //using lower_bound to find the sum no greater than k
                set<int> s;
                int cur_sum = 0;
                s.insert(cur_sum);
                for (auto& sum: col_sum)
                {
                    cur_sum += sum;
                    auto it = s.lower_bound(cur_sum - k);
                    if (it != s.end())
                        ans = max(ans, cur_sum - *it);
                    if (ans == k)
                        return k;
                    s.insert(cur_sum);
                }
            }
        }
        return ans;
    }
};


Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).


/*
https://practice.geeksforgeeks.org/problems/maximum-sum-of-subarray-less-than-or-equal-to-x4033/1/#

[[5,-4,-3,4],[-3,-4,4,5],[5,1,5,-4]]
10
*/
