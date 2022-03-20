
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
vector<pair<double,double>> v;
        double ans = 0.0;
        for(int i=0;i<n;i++){
            v.push_back({arr[i].value,arr[i].weight});
       }
       auto comp  = [&](pair<double,double>& a,pair<double,double>& b){
           return (double)a.first/a.second > (double)b.first/b.second;
       };
       sort(v.begin(),v.end(),comp);
       for(int i=0;i<n;i++){
           if(v[i].second<=W){
               ans += v[i].first;
               W -= v[i].second;
           }else{
               ans += (double)(W*(v[i].first/v[i].second));
               break;
           }
       }
       return ans;
           }
        
};
