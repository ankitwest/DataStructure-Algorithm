
// TLE

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(); int m = nums2.size();
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum = nums1[i]+nums2[j];
                pq.push({sum,{nums1[i],nums2[j]}});
                if(pq.size()>k) pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(pq.size()){
            auto curr = pq.top(); pq.pop();
            ans.push_back({curr.second.first,curr.second.second});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// Success      464ms
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(); int m = nums2.size();
        priority_queue<pair<int,pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum = nums1[i]+nums2[j];
                if(pq.size()<k)  pq.push({sum,{nums1[i],nums2[j]}});
                else if(pq.top().first>sum) {pq.pop(); pq.push({sum,{nums1[i],nums2[j]}});}
                else break;
            }
        }
        vector<vector<int>> ans;
        while(pq.size()){
            auto curr = pq.top(); pq.pop();
            ans.push_back({curr.second.first,curr.second.second});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]




// M - 2

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(); int m = nums2.size();
        vector<vector<int>> ans;
        
        priority_queue<tuple<int,int,int>> pq;
        pq.push({-nums1[0]-nums2[0],0,0});   //-ve to use maxHeap as minHeap
        
        while(!pq.empty() and ans.size()<k){
            auto curr = pq.top(); pq.pop();
            int i = get<1>(curr); int j = get<2>(curr);
            ans.push_back({nums1[i],nums2[j]});
            
            if(j==0 and i+1<n) pq.push({-nums1[i+1]-nums2[j],i+1,j});
            if(i<n and j+1<m) pq.push({-nums1[i]-nums2[j+1],i,j+1});
        }
        return ans;
    }
   };
