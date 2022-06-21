class Solution1 {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq; int k = ladders;
        int sum = 0;
        int i=0;
        for(i=1;i<heights.size();i++){
            if(heights[i] <= heights[i-1]) continue;
            int diff = heights[i] - heights[i-1];
            pq.push(diff);
            sum += diff;

            while(k > 0 and sum > bricks){
                int tp = pq.top(); pq.pop();
                sum -= tp;
                k--;
            }
            if(sum > bricks){
                 break;
            }
        }
        return i-1;
    }
};



class Solution {
public:  // negative
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq; int k = ladders;
        int i=0;
        for(i=1;i<heights.size();i++){
            if(heights[i] <= heights[i-1]) continue;
            int diff = heights[i] - heights[i-1];
            pq.push(-diff);  
            
            if(pq.size() > k)
                bricks += pq.top(),pq.pop();
            
            if(bricks<0)
                return i-1;
        }
        return heights.size()-1;
    }
};


Input: heights = [4,2,7,6,9,14,12], bricks = 5, ladders = 1
Output: 4
Explanation: Starting at building 0, you can follow these steps:
- Go to building 1 without using ladders nor bricks since 4 >= 2.
- Go to building 2 using 5 bricks. You must use either bricks or ladders because 2 < 7.
- Go to building 3 without using ladders nor bricks since 7 >= 6.
- Go to building 4 using your only ladder. You must use either bricks or ladders because 6 < 9.
It is impossible to go beyond building 4 because you do not have any more bricks or ladders.
Example 2:

Input: heights = [4,12,2,7,3,18,20,3,19], bricks = 10, ladders = 2
Output: 7
Example 3:

Input: heights = [14,3,19,3], bricks = 17, ladders = 0
Output: 3
