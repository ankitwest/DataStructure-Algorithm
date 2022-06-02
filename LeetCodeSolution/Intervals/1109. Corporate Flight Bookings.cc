

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> sweep(n+1,0);
        for(auto book : bookings){
            sweep[book[0]-1] += book[2];
            sweep[book[1]]   -= book[2];
        }
        
        vector<int> ans(n,0);
        ans[0] = sweep[0];
        for(int i=1;i<n;i++){
            ans[i] = sweep[i] + ans[i-1];
        }
        return ans;
    }
};

Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
Output: [10,55,45,25,25]
Explanation:
Flight labels:        1   2   3   4   5
Booking 1 reserved:  10  10
Booking 2 reserved:      20  20
Booking 3 reserved:      25  25  25  25
Total seats:         10  55  45  25  25
Hence, answer = [10,55,45,25,25]
