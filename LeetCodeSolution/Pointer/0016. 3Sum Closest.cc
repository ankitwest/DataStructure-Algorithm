class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        int sum_st = 0;
        int ans = INT_MAX;  
        int n = a.size();
        for(int i=0;i<n;i++){
            int j = i+1; int k = n-1;
            while(j<k){
                int sum = a[i] + a[j] + a[k];
                if(sum > target) {
                    k--;
                    if(abs(target - sum) < ans)
                        ans = abs(target - sum), sum_st = sum;
                }else if(sum < target) {
                    j++;
                    if(abs(target - sum) < ans)
                        ans = abs(target - sum), sum_st = sum;
                }else{
                    return sum;
                }
            }
        }
        return sum_st;
    }
};00
