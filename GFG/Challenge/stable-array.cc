class Solution{
public:
  int stableArray(vector<int>& a){
      int n = a.size();
      map<int,int>m;
     for(int i=0;i<n;i++){
         m[a[i]]++;
     }
     vector<int> freq;
     for(auto i:m) freq.push_back(i.second);
     sort(freq.begin(),freq.end());
     
     
     int max_count = INT_MIN; 
     for(int i=0;i<freq.size();i++){
         int idx = lower_bound(freq.begin(),freq.end(),freq[i]) - freq.begin();
         int x = freq.size() - idx;
        //  no of x elements with count of freq[i];
        max_count = max(max_count , x*freq[i]);
     }
     return n - max_count;
  }
};

Input : a[] = {4,3,1,3,1,2}
Output :  2
Explanation : If we remove 1st and last element from
the given array, then the array will be stable
resultant array: 3 1 3 1 (every element occure only 2 times)

Input : a[] = {1,1,2,4,1,2,2}
Output : 1
Explanation : If we remove 4th element i.e. 4, 
then the array will be stable 
resultant array: 1 1 2 1 2 2 (every element occure 
