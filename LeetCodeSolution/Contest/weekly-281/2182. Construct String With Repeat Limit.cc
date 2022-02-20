class Solution {
public:
    string repeatLimitedString(string s, int k) {
        int cnt[26] = {0}; int n = s.size();
        for(auto c:s) cnt[c-'a']++;

        priority_queue<pair<int,int>> pq;
        for(int i=0;i<26;i++){
            if(cnt[i]>0)
            pq.push({i,cnt[i]});
        }
        
        string ans="";
        
        while(!pq.empty()){
            auto l = pq.top(); pq.pop();
             if(ans.size()==0 or ans.back()!=('a' + l.first)){
                  int mini = min(k,l.second);
                 if(l.second-mini>0) pq.push({l.first,l.second-mini});
                 while(mini--) ans += 'a' + l.first;
             }else {  
                 if(pq.size()==0) break;
                  auto s = pq.top(); pq.pop();
                if(s.second-1>0) pq.push({s.first,s.second-1});
                  if(l.second>0) pq.push({l.first,l.second});
                
                ans += 'a' + s.first;
             }
        }
         return ans;
    }

};
Input: s = "aababab", repeatLimit = 2
Output: "bbabaa"
  
//         while(pq.size()>1){
//             auto l = pq.top(); pq.pop();
//             auto s = pq.top(); pq.pop();
            
//             if(ans.size()==0 or ans.back()!=('a' + l.first)){
//                 int mini = min(k,l.second);
//                 if(l.second-mini>0) pq.push({l.first,l.second-mini});
//                 if(s.second-1>0) pq.push({s.first,s.second-1});
                
//                  while(mini--) ans += 'a' + l.first;
//                  if(s.second>0) ans += 'a' + s.first;  
                
//             }else if(ans.back()==('a' + l.first)){
//                 int cnt = 0;
//                 for(int i=ans.size()-1;i>=0;i--){
//                     if(ans[i]==('a' + l.first)) cnt++; else break;
//                 }
//                 int repReq = k - cnt;
//                 if(l.second-repReq>0) pq.push({l.first,l.second-repReq});
//                 if(s.second-1>0) pq.push({s.first,s.second-1});
                
//                 while(repReq--) ans += 'a' + l.first;
//                 if(s.second>0) ans += 'a' + s.first;
//             }
//         }
        
//         auto last = pq.top(); pq.pop();
//         int ctr = 0;
//         for(int i=ans.size()-1;i>=0;i--){
//             if(ans[i]==('a' + last.first)) ctr++; else break;
//         }

//         int repReq = k - ctr;
//         int mini = min(repReq,last.second);
//         while(mini--) ans += 'a' + last.first;
        
//         return ans;
//    }
