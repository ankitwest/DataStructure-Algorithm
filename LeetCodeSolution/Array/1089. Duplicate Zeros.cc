

class Solution1 {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> ans;
        for(auto i:arr){
            if(i==0) ans.push_back(0),ans.push_back(0);
            else ans.push_back(i);
            if(ans.size()>arr.size()) ans.pop_back();
        }
        if(ans.size()>arr.size()) ans.pop_back();
        arr = ans;
    }
};
// SC - O(N) TC - O(N)
class Solution2 {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
        int i=0,j=0;
        while(j<n){
            if(arr[i]>0) ans[j++] = arr[i++];
            else {
                ans[j++] = arr[i]; 
                if(j<n) ans[j++] = arr[i++];
            }
        }
        arr = ans;
    }
};

// SC - O(1) TC - O(N)
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int shift = count(arr.begin(),arr.end(),0); int size = arr.size();
        for(int i=size-1;i>=0;i--){
            if(arr[i]==0) shift--;
            if(i + shift < size){
                arr[i + shift] = arr[i];
                if(arr[i]==0 and i + shift + 1 < size)
                    arr[i + shift + 1] = 0;
            }
        }
    }
};

nput: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4
