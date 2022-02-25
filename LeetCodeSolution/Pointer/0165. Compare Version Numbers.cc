class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n1 = v1.size(); int n2 = v2.size();
        int i=0,j=0;  int num1=0; int num2=0;
        
        while(i<n1 or j<n2){
            while(i<n1 and v1[i]!='.'){
                num1 = num1*10 + (v1[i]-'0');
                i++;
            }
            while(j<n2 and v2[j]!='.'){
                num2 = num2*10 + (v2[j]-'0');
                j++;
            }
            if(num1<num2) return -1;
            if(num1>num2) return 1;
            
            num1=0,num2=0;
            i++,j++;
        }
        return 0;
    }
};


Example 2:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: version1 does not specify revision 2, which means it is treated as "0".
Example 3:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Explanation: version1's revision 0 is "0", while version2's revision 0 is "1". 0 < 1, so version1 < version2.
    
    
    
    
    class Solution:
    def compareVersion(self, v1: str, v2: str) -> int:
        v1 = list(map(int,v1.split('.')))
        v2 = list(map(int,v2.split('.')))
        
        for rev1 ,rev2 in zip_longest(v1,v2,fillvalue = 0):
            if rev1 == rev2:
                continue
            return 1 if rev1 > rev2 else -1
        
        return 0
