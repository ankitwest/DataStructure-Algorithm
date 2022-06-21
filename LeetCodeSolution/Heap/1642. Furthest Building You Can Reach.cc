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
