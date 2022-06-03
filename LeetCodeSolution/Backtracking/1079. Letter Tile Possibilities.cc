

class Solution {
public:     //similar to permutations ii
    int count = -1;
    void solve(string tiles,int level){
        count++;
        
        for(int i=level;i<tiles.size();i++){
            if(i!=level and tiles[i]==tiles[level]) continue;
            swap(tiles[i],tiles[level]);
            solve(tiles,level+1);
        }
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        solve(tiles,0);
        
        return count;
    }
};


Input: tiles = "AAB"
Output: 8
Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
