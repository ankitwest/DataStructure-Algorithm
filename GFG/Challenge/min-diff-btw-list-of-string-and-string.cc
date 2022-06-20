class Solution{
public:
  int getMinDiff(int freq1[],int freq2[]){
      int cnt = 0;
      for(int i=0;i<26;i++){
          if(freq2[i]>0)
          cnt += abs(freq1[i]-freq2[i]);
      }
      return cnt;
  }
      
    int minimumDifference(string s, vector<string> list) {
      int d = INT_MAX;
      for(auto word : list)
      {
          int freq1[26] = {0};
          int freq2[26] = {0};
          
          int i=0,l=0;
          while(i<word.size())
          {
              freq1[word[i]-'a']++;
              freq2[s[i]-'a']++;
              i++;
          }
          d = min(d,getMinDiff(freq1,freq2));
          
          while(i<s.size())
          {
              freq2[s[l]-'a']--;
              freq2[s[i]-'a']++;
              d = min(d,getMinDiff(freq1,freq2));
              i++,l++;
          }
      }
      return d;
    }
    };
    
    
    input: S = abcde
list[] = {cdf,efd,klda,eaf}
Output: 1
Explanation: 
Difference of the string cdf with the
substring cde is 1.
Difference of the string efd with the
substring cde is 1 if we rearrange the
characters of efd.
Difference of the string klda with the
substring abcd is 2 if we rearrange the
characters of klda.
Difference of the string eaf with the
substring cde is 2 if we rearrange the
characters of efd.
So minimum difference is 1.

Input: S = abc
list[] = {abd,ace,ab}
Output: 0
