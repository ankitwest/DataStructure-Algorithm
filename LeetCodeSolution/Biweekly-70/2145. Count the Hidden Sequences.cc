class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
         int n = diff.size(); 
        long long sum = 0; long long mini=sum, maxi=sum;
        for(int i=0;i<n;i++){
            sum += diff[i];
            maxi = max(maxi,sum);
            mini = min(mini,sum);
        }
        // a+sth <= upper   a+sth>=lower
        
        long long r = upper-maxi; long long l = lower-mini;
        return (r-l+1)>0?(r-l+1):0;
    }
};

// Using math taking a as first value and then doing all the calculation
