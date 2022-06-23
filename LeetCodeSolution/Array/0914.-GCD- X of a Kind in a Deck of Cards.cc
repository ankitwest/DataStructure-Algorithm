class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> m; int n = deck.size();
        for(int i=0;i<n;i++) m[deck[i]]++;
        int gcd = 0;
        for(auto [x,y]:m) 
            gcd = __gcd(gcd,y);
        return gcd > 1;
    }
};

Input: deck = [1,2,3,4,4,3,2,1]
Output: true
Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
Example 2:

Input: deck = [1,1,1,2,2,2,3,3]
Output: false
Explanation: No possible partition.
