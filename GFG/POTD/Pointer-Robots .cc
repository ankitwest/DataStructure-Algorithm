

class Solution{   
public:
    string moveRobots(string s1, string s2){
        int i=0,j=0; int n=s1.size();
        while(i<n and j<n){
            while(s1[i]=='#') i++;
            while(s2[j]=='#') j++;
            
            if(s1[i]!=s2[j]) return "No";
            else if(s1[i]=='B' and s2[j]=='B' and i>j) return "No";
            else if(s1[i]=='A' and s2[j]=='A' and i<j) return "No";
            else i++,j++;
        }
        return "Yes";
    }
  };
