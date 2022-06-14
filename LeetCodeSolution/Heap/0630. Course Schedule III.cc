class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[&](auto &a, auto &b){
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        
        int time = 0;
        for(auto c : courses){
            int dur = c[0]; int end = c[1];
            pq.push(dur);
            time += dur;
            if(time > end){
                time -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};

courses[i] = [durationi, lastDayi] in

Input: courses = [[100,200],[200,1300],[1000,1250],[2000,3200]]
Output: 3
Explanation: 
There are totally 4 courses, but you can take 3 courses at most:
