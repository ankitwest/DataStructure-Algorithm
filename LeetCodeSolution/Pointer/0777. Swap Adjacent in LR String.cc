


class Solution {
public:
    bool canTransform(string s, string t) {
        int n = s.size();
        vector<pair<char,int>> vp1,vp2;
        for(int i=0;i<n;i++){
            if(s[i]!='X') vp1.push_back({s[i],i+1});
            if(t[i]!='X') vp2.push_back({t[i],i+1});
        }
        if(vp1.size()!=vp2.size())  return false;
        
        for(int i=0;i<vp1.size();i++){
            if(vp1[i].first != vp2[i].first) return false;
            else {
                if(vp1[i].first == 'R')
                    {if(vp1[i].second > vp2[i].second) return false;}
                else if(vp1[i].first == 'L')
                    {if(vp1[i].second < vp2[i].second) return false;}
            }
        }
        return true;
    }
};

// we can move 'L' left and 'R' right

Input: start = "RXXLRXRXL", end = "XRLXXRRLX"
Output: true
Explanation: We can transform start to end following these steps:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
