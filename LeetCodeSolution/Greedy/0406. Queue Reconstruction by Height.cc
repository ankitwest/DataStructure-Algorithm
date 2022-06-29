class Solution {
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]) return a[1]<b[1];
        return a[0]>b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(),comp);
        // for(auto v:people){
        //     cout<<v[0]<<" "<<v[1]<<endl;
        // }
        vector<vector<int>> ans;
        for(auto v : people){
            auto pos = ans.begin() + v[1];
            ans.insert(pos, v);
        }
        return ans;
    }
};

/*
sort -  7,0 7,1 6,0 5,0 5,3 
after insertion -  5,0 6,0 7,0 5,3 7,1
*/
