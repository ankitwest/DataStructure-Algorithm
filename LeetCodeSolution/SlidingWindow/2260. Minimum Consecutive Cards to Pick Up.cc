class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();  int len = INT_MAX;
        int last[1000000+1]; memset(last,0,sizeof(last));
        for(int i=0;i<n;i++){
            if(last[cards[i]])
                len = min(len,(i+1)-last[cards[i]]+1);
            last[cards[i]] = i+1;  
        }
        return len == INT_MAX ? -1 : len;
    }
};

Input: cards = [3,4,2,3,4,7]
Output: 4
Explanation: We can pick up the cards [3,4,2,3] which contain a matching pair of cards with value 3. Note that picking up the cards [4,2,3,4] is also optimal.
