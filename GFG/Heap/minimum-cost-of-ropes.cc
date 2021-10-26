class Solution{
public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        priority_queue<long long,vector<long long>,greater<long long> > minpq;
        for(int i=0;i<n;i++){
            minpq.push(arr[i]);
        }
        long long sum=0;
        long long ans=0;
        long long a=0,b=0;
        
        while(minpq.size()>=2){
            a = minpq.top();minpq.pop();
            b = minpq.top();minpq.pop();
            sum = a+b;
            minpq.push(sum);
            ans += sum;
        }
        return ans;
    }
};

Expected Time Complexity : O(nlogn)
Expected Auxilliary Space : O(n)
