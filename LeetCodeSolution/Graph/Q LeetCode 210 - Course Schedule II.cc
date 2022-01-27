class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result(numCourses);
        if (numCourses == 0) {
            return result;
        }

        if (prerequisites.empty()) {
            for (int i = 0; i < numCourses; i++) {
                result[i] = i;
            }
            return result;
        }

        vector<int> indegree(numCourses);
        queue<int> zeroDegree;
        for (vector<int>& pre : prerequisites) {
            indegree[pre[0]]++;
        }
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                zeroDegree.push(i);
            }
        }
        if (zeroDegree.empty()) {
            return vector<int>();
        }

        int index = 0;
        while (!zeroDegree.empty()) {
            int course = zeroDegree.front();
            zeroDegree.pop();
            result[index] = course;
            index++;
            for (vector<int>& pre : prerequisites) {
                if (pre[1] == course) {
                    indegree[pre[0]]--;
                    if (indegree[pre[0]] == 0) {
                        zeroDegree.push(pre[0]);
                    }
                }
            }
        }

        for (int in : indegree) {
            if (in != 0) {
                return vector<int>();
            }
        }

        return result;
    }
};
