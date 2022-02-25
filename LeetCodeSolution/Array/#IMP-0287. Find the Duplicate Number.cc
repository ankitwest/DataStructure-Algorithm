
M-1
class Solution {
public:
      int findDuplicate(vector<int>& nums) {
        int n=nums.size();
          map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;   
        }
          for(auto x:m)
              if(x.second>1)
                  return x.first;
          
        return 0;

      }
};

 TC- O(NlogN)
  SC -0(N)
   
   
       
   M-2
class Solution {
public:
      int findDuplicate(vector<int>& nums) {
          int n = nums.size();
          vector<int> freq(n+1,0);
          for(int i=0;i<n;i++){
              if(freq[nums[i]]==1) return nums[i];
              else freq[nums[i]]++;
          }
          return -1;
    }
 };
Runtime: 135 ms, 
  TC- O(N)
  SC -0(N)

    
    
M-3
    
class Solution {
public:
      int findDuplicate(vector<int>& nums) {
        int slow = nums[0],fast = nums[0];
          
          do{
              slow = nums[slow];
              fast = nums[nums[fast]];
          }while(slow!=fast);
          
          fast = nums[0];
          
          while(slow!=fast){
              slow = nums[slow];
              fast = nums[fast];
          }
          
          return slow;
    }
};
Runtime: 178 ms, 
    
  TC- O(N)
  SC -0(1)

        
        
   
        
        
    M - 4 
        class Solution {
public:
      int findDuplicate(vector<int>& a) {
         int x=0; 
        for(int i=0;i<a.size();i++){
            if(a[abs(a[i])-1]<0) return abs(a[i]);
            else x = a[abs(a[i])-1], x*= -1 , a[abs(a[i])-1]=x;
        }
         return -1;
    }
};
  TC- O(N)
  SC -0(1)
