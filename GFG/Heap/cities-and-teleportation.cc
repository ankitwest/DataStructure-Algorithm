
class Solution{
    public:
    int solve (int N,vector<int> &A,int X,int K)
    {
        priority_queue<int> pq;
        int i=1; int sum=0;
        for(i=1;i<N;i++){
            int diff = A[i]-A[i-1];
            pq.push(diff);
            sum += diff;
            while(K>0 and X<sum and !pq.empty()){
                int curr = pq.top(); pq.pop();
                sum -= curr;
                K--;
            }
            if(sum>X) break;
        }
        return i;
    }
};

Input: 
N = 4, X = 2,K = 2
A[] = {0,1,2,3}
Output: 
4
Explanation: 
You can use teleporters of city 1 and 2
and then travel from the 3rd city to the
4th city.
