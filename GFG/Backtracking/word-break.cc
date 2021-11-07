// BackTracking 
// Not understood
class Solution
{
public:
    bool wordBreakUtil(int i,int j,int l,string &A,vector<string> &B){

        if(j == l){
            if(i == l) return true;
             return false;
         }
    
        if(find(B.begin(),B.end(),A.substr(i,j-i+1))==B.end())  // string from pos i to j
            return wordBreakUtil(i,j+1,l,A,B);    // even if found we inc by j by 1
        else{
            if(wordBreakUtil(i,j+1,l,A,B)) return true;
            return wordBreakUtil(j+1,j+1,l,A,B);
        }
    }
    int wordBreak(string A, vector<string> &B) {
      return wordBreakUtil(0,0,A.size(),A,B);
    }
};
