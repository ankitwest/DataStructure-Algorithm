/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id){
        int n = employees.size();
        map<int, int> m1; 
        map<int, vector<int>> m2;
        for(auto e : employees){
            m1[e->id] = e->importance;
            m2[e->id] = e->subordinates;
        }
        
        queue<int> q;
        q.push(id); int cnt = 0;
        while(!q.empty())
        {
            auto c_id = q.front(); q.pop();
            cnt += m1[c_id];
            auto v = m2[c_id];
            for(auto ch_id : v)
            {
                q.push(ch_id);
            }
        }
        return cnt;
    }
};
