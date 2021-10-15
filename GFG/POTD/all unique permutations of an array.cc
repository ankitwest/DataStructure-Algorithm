
class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
        // int n = arr.size();
        set<vector<int>> s;
        sort(arr.begin(),arr.end());
        do{
            s.insert(arr);
        } while (next_permutation(arr.begin(),arr.end()));
        
        vector<vector<int>> v;
        // cout<<s.size()<<endl;
        for(auto x:s){
            v.push_back(x);
        }
        return v;
    }
};
