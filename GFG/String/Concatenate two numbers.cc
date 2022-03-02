class Solution{
    public:
    long long countPairs(int n, int x, vector<int> numbers){
        vector<string> num ;
        for(auto it:numbers) 
            num.push_back(to_string(it));
        map<string,long long> mp;
        for(auto it:num) 
            mp[it]++;
            
        long long ans = 0; string s = to_string(x);
        for(int i=1;i<s.size();i++){
            string a = s.substr(0,i);
            string b = s.substr(i);
            
            if(a!=b)
                ans += mp[a]*mp[b];
            else
                 ans += mp[a]*(mp[a]-1);
        }
        return ans;
    }
}; 

Input:
N = 4 
numbers[] = {1, 212, 12, 12}
X = 1212
Output:
3
Explanation:
We can obtain X=1212 by concatenating:
numbers[0] = 1 with numbers[1] = 212
numbers[2] = 12 with numbers[3] = 12
numbers[3] = 12 with numbers[2] = 12
  
 
  Input: 
N = 3
numbers[] = {11, 11, 110}
X = 11011
Output:
2
Explanation:
We can obtain X=11011 by concatenating:
numbers[2] = 110 with numbers[0] = 11
numbers[2] = 110 with numbers[1] = 11
