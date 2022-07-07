class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),[&](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]) return a[1] > b[1];
            return a[0] < b[0]; 
        });
        // 1,2  4,3 4,4  5,4 5,2 5,1
        // attack defence
        
        int n = properties.size();
        int def = properties[n-1][1]; int cnt = 0;
        for(int i=n-2;i>=0;i--){
            if(properties[i][1] < def){
                cnt++;
            }else{
                def = max(def, properties[i][1]);
            }
        }
        return cnt;
    }
};

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),[&](vector<int> &a,vector<int> &b){
            if(a[1]==b[1]) return a[0] > b[0];
            return a[1] < b[1]; 
        });
        // 5,1  5,2 1,2  4,3  5,4 4,4  
        // attack defence
        
        int n = properties.size();
        int att = properties[n-1][0]; int cnt = 0;
        for(int i=n-2;i>=0;i--){
            if(properties[i][0] < att){
                cnt++;
            }else{
                att = max(att, properties[i][0]);
            }
        }
        return cnt;
    }
};

/*
[[5,4],[5,2]]
[[1,2],[4,3],[4,4],[5,4],[5,2],[5,1]]
*/

Input: properties = [[5,5],[6,3],[3,6]]
Output: 0
Explanation: No character has strictly greater attack and defense than the other.
