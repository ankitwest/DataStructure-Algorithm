
class Solution{
public:
    string chooseandswap(string s){
        vector<int> v(26,-1);
        int i=0;
        for(auto c:s){
            if(v[c-'a']==-1) v[c-'a']=i;
            i++;
        }
        
        char x,y; int f=0;
        for(auto c:s){
            for(char ch='a';ch<c;ch++){
                if(v[ch-'a']!=-1 and v[ch-'a']>v[c-'a']) {x=c,y=ch; f=1;break;}
            }
            if(f) break;
        }
        if(!f) return s;
        
        for(auto &c:s){
            if(c==x) c=y;
            else if(c==y) c=x;
        }
        return s;
    }
    
    };




Input:
A = "ccad"
Output: "aacd"
Explanation:
In ccad, we choose a and c and after 
doing the replacement operation once we get, 
aacd and this is the lexicographically
smallest string possible.
